from qiling import Qiling
from qiling.const import QL_VERBOSE, QL_INTERCEPT
from qiling.extensions import pipe

from elftools.elf.elffile import ELFFile
from pprint import pprint
from capstone import *
import tempfile
from flask import Flask, request, render_template, jsonify
import os
import shutil
from werkzeug.utils import secure_filename
import logging.handlers
import logging
import sys
import random

app = Flask(__name__)

handler = logging.StreamHandler(sys.stdout)
app.logger.addHandler(handler)
app.logger.setLevel(logging.INFO)

UPLOAD_FOLDER = "uploads"
os.makedirs(UPLOAD_FOLDER, exist_ok=True)
app.config["UPLOAD_FOLDER"] = UPLOAD_FOLDER


class MovInOpcode(Exception):
    pass

class WrongOutputFormat(Exception):
    pass

md = Cs(CS_ARCH_X86, CS_MODE_64)
GLIBC_ROOTFS = "./rootfs/x8664_linux_glibc2.39"


def get_main_function_range(elf_file_path):
    with open(elf_file_path, 'rb') as f:
        elf = ELFFile(f)
        
        # Get the symbol table
        symbol_table = elf.get_section_by_name('.symtab')
        if symbol_table is None:
            raise Exception("No symbol table found in ELF file")

        # Look for the main function in the symbol table
        main_symbol = None
        for symbol in symbol_table.iter_symbols():
            if symbol.name == 'main':
                main_symbol = symbol
                break
        
        if main_symbol is None:
            raise Exception("No 'main' function found in the symbol table")

        # Get the relative address of 'main' (within the .text section)
        main_relative_address = main_symbol['st_value']
        app.logger.info(f"Relative address of 'main': 0x{main_relative_address:x}")
        
        # Find the section that contains the main function (usually .text)
        text_section = elf.get_section_by_name('.text')
        if text_section is None:
            raise Exception("No .text section found in ELF file")

        # Get the base address of the .text section (absolute address)
        text_base_address = text_section['sh_addr']
        app.logger.info(f"Base address of .text section: 0x{text_base_address:x}")

        # Get the end of the .text section (absolute address)
        text_end_address = text_base_address + text_section['sh_size']
        app.logger.info(f".text section ends at: 0x{text_end_address:x}")

        # Return the absolute address range for the main function (it is typically within the .text section)
        return main_relative_address, text_end_address+0x500

    

def get_binary_range(ql):
    """
    Get the memory range where the binary is loaded.
    """

    app.logger.info("\n".join(ql.mem.get_formatted_mapinfo()))

    for map in ql.mem.get_mapinfo():
        # if ((map[3] in binary_path) and ('x' in map[2])):
        if (map[3] in filepath):
            start_addr, end_addr = map[0], map[1]
            return start_addr, end_addr
    return None, None


# def check_prime_opcode(opcode):
#     global seen_primes

#     # opcode is a bytearray
#     for index, opcode_byte in enumerate(opcode):
#         opcode_byte_in_dec = int(opcode_byte)
        
#         if isprime(opcode_byte_in_dec):
#             hex_prime_opcode = hex(opcode_byte_in_dec)
#             if not(hex_prime_opcode in seen_primes):
#                 seen_primes.append(hex_prime_opcode)
#             raise PrimeInOpcode(f"Opcode at position {index} is prime in dec")

#     return False


def check_mov_opcode(opcode):
    app.logger.info(opcode.hex())
    for instr in md.disasm(opcode, 0):
            if instr.mnemonic.startswith("mov"):
                app.logger.info(f"MOV instruction at : {instr.mnemonic} {instr.op_str}")
                raise MovInOpcode



def hook_instruction(ql, address, size):
    """
    Hook each instruction for debugging or custom checks.
    """
    global mov_count
    global mov_list
    
    if main_start <= address < main_end:
        # Read the current instruction
        opcode = ql.mem.read(address, size)
        regs = ql.arch.regs

        try:
            check_mov_opcode(opcode)
        except MovInOpcode as e:
            app.logger.info(e)
            mov_count += 1
            mov_list.append(f"mov instructions at addr {hex(address - binary_start)}: {opcode.hex()}")
            pass



def test_program(binary_path, test_input):
    with tempfile.TemporaryDirectory() as temp_rootfs:
        # Create a Qiling instance with rootfs
        shutil.copytree(GLIBC_ROOTFS, temp_rootfs, dirs_exist_ok=True)
        ql = Qiling([binary_path, str(test_input[0]), str(test_input[1]), str(test_input[2])], temp_rootfs, verbose=QL_VERBOSE.DISABLED)
        
        ql.os.stdout = pipe.SimpleOutStream(1)


        # Hook dangerous syscalls (like execve, fork, etc.)
        def syscall_hook(ql, sys_num):
            if sys_num in {59, 57, 58}:  # execve, fork, vfork
                app.logger.info(f"Blocked dangerous syscall: {sys_num}")
                ql.stop()


        # Hook some dangerous call; probably not enough at all
        ql.os.set_syscall('fork', syscall_hook, QL_INTERCEPT.CALL)
        ql.os.set_syscall('vfork', syscall_hook, QL_INTERCEPT.CALL)
        ql.os.set_syscall('execve', syscall_hook, QL_INTERCEPT.CALL)
        ql.os.set_syscall('clone', syscall_hook, QL_INTERCEPT.CALL)
        
        global binary_start, binary_end
        global main_start, main_end

        global mov_count, mov_list
        mov_count = 0
        mov_list = []

        binary_start, binary_end = get_binary_range(ql)
        app.logger.info(f"Binary starts {hex(binary_start)}, ends {hex(binary_end)}")

        main_start_offset, main_end_offset = get_main_function_range(binary_path)
        main_start = binary_start + main_start_offset
        main_end = binary_start + main_end_offset
        
        app.logger.info(f"Main starts {hex(main_start)}, ends {hex(main_end)}")
        
        # Hook instructions
        ql.hook_code(hook_instruction)

        # Start the emulation
        ql.run()

        try:
            output = ql.os.stdout.read().decode('utf-8').strip()
            if output.startswith("Sum: "):
                program_sum = int(output.split("Sum: ")[1])
                app.logger.info(f"Program sum: {program_sum}")
            else:
                raise WrongOutputFormat

            return mov_count, mov_list, program_sum
        
        except Exception as e:
            app.logger.info(str(e))
        
        



def is_valid_elf(filepath):
    """Check if file is a valid x86-64 ELF."""
    try:
        with open(filepath, "rb") as f:
            elf = ELFFile(f)
            return elf.header["e_machine"] == "EM_X86_64"
    except Exception:
        return False
    

@app.route("/", methods=["GET", "POST"])
def upload_file():
    global mov_count, mov_list
    messages = {"success": None, "error": None}


    if request.method == "POST":
        input_tests = [[1,2,3],\
                    [100,200,300],\
                    [random.randint(0,14000), random.randint(0,14000), random.randint(0,14000)],\
                    [random.randint(0,14000), random.randint(0,14000), random.randint(0,14000)],\
                    [random.randint(0,14000), random.randint(0,14000), random.randint(0,14000)]]
        try:
            if "file" not in request.files:
                messages["error"] = "No file uploaded"
                return render_template("index.html", messages=messages)

            file = request.files["file"]
            if not file:
                messages["error"] = "No file uploaded"
                return render_template("index.html", messages=messages)
            
            filename = secure_filename(file.filename)

            global filepath
            
            filepath = os.path.join(app.config["UPLOAD_FOLDER"], filename)
            file.save(filepath)

            if not is_valid_elf(filepath):
                messages["error"] = "Not a valid x86-64 ELF"
            else:
                for input_test in input_tests:
                    mov_count = 0
                    mov_list = []
                    mov_count, mov_list, computed_sum = test_program(filepath, input_test)
                    if mov_count > 4:
                        messages["error"] = f"You're moving too much! ({mov_count} times):\n" + "\n".join(mov_list)
                        return render_template("index.html", messages=messages)
                    if computed_sum != sum(input_test):
                        messages["error"] = f"The math ain't mathing ...:\nInput:" + ','.join(input_test) + "\nYour sum: " + str(computed_sum)
                        return render_template("index.html", messages=messages)
                    
                messages["success"] = "Good job! ATHACKCTF{IDoNOTLikeToMovItMovIt}"
                return render_template("index.html", messages=messages)

        except Exception as e:
            print(e)
            messages["error"] = str(e)
    
    return render_template("index.html", messages=messages)


if __name__ == "__main__":
    app.run(debug=False)