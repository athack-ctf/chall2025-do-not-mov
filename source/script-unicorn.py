from __future__ import print_function
import pefile, collections
from unicorn import *
from unicorn.x86_const import *


from elftools.elf.elffile import ELFFile
from io import BytesIO

import struct

IMAGE_FILE_MACHINE_I386 = 0x014c
IMAGE_FILE_MACHINE_AMD64 = 0x8664

"""
    Usage Example: 
        # run shellcode 
        # read bytes 
        instructions = b"\x90\x90\x90\x90""
        # init unicorn instance, allocate memory, create stack, etc 
        tt = InitUnicorn(instructions)
        # emulate code standard unicorn start arguments
        tt.mu.emu_start(tt.code_base, tt.code_base + len(instructions))
        # read register value 
        r_eip = tt.mu.reg_read(UC_X86_REG_EIP)
        print("0x%x" % r_eip)
        
        # read 32-bit executable 
        data = open("bad_file.exe", "rb").read()
        # options data, type_pe=False, bit=32, debug=False)
        tt = InitUnicorn(data, type_pe=True, debug=True)
        
        try:
            # Verbose, if it works set DEBUG False 
            tt.DEBUG = True
            # emulate virtual address 
            tt.mu.emu_start(0x0405490, 0x0405490 + 0x1C)
            r_eax = tt.mu.reg_read(UC_X86_REG_EAX)
            print("0x%x" % r_eax)
        
        except Exception as e:
            print("0x%x" % (tt.mu.reg_read(UC_X86_REG_ESP)))
            print(e)
"""


class InitUnicorn(object):
    def __init__(self, data, bit=64, debug=False):
        self.code_base = 0x0
        self.DEBUG = debug
        # pe check
        if bit == 32:
            self.is_x86_machine = True
        else:
            self.is_x86_machine = False
        self.init_unicorn()

        self.program = data

        self.map_data(data)

        self.create_stack()
        if self.DEBUG:
            self.add_debug()

    def create_stack(self):
        self.is_x86_machine = False
        self.stack_base = 0xffff00000000
        self.stack_size = 0x000000100000
        self.mu.mem_map(self.stack_base, self.stack_size)
        self.mu.mem_write(self.stack_base, b"\x00" * self.stack_size)
        if self.is_x86_machine:
            self.mu.reg_write(UC_X86_REG_ESP, self.stack_base + 0x800)
            self.mu.reg_write(UC_X86_REG_EBP, self.stack_base + 0x1000)
        else:
            self.mu.reg_write(UC_X86_REG_RSP, self.stack_base + 0x8000)
            self.mu.reg_write(UC_X86_REG_RBP, self.stack_base + 0x10000)

    def init_unicorn(self):
        if self.is_x86_machine:
            self.mu = Uc(UC_ARCH_X86, UC_MODE_32)
        else:
            self.mu = Uc(UC_ARCH_X86, UC_MODE_64)

    def map_data(self, data):
        self.mu.mem_map(self.code_base, 0x10000)
        self.mu.mem_write(self.code_base, data)



    def add_debug(self):
        ## Debugging use only
        self.mu.hook_add(UC_HOOK_CODE, self.hook_code)
        # self.mu.hook_add(UC_HOOK_INSN, self.hook_call, None, 1, 0, UC_X86_INS_CALL)
        self.mu.hook_add(UC_HOOK_MEM_INVALID, self.hook_mem_invalid)

    def hook_code(self, uc, address, size, user_data):
        ## Debugging use only
        print('>>> Tracing instruction at 0x%x, instruction size = 0x%x' % (address, size))
        ## Put checker code here

    def hook_call(self, uc, address, size, user_data):
        ## Debugging use only
        print('>>> Call instruction at 0x%x, instruction size = 0x%x' % (address, size))

    def hook_mem_invalid(self, uc, access, address, size, value, user_data):
        ## Debugging use only
        eip = uc.reg_read(UC_X86_REG_EIP)
        if access == UC_MEM_WRITE:
            print("invalid WRITE of 0x%x at 0x%X, data size = %u, data value = 0x%x" % (address, eip, size, value))
        if access == UC_MEM_READ:
            print("invalid READ of 0x%x at 0x%X, data size = %u" % (address, eip, size))
        if access == UC_MEM_FETCH:
            print("UC_MEM_FETCH of 0x%x at 0x%X, data size = %u" % (address, eip, size))
        if access == UC_MEM_READ_UNMAPPED:
            print("UC_MEM_READ_UNMAPPED of 0x%x at 0x%X, data size = %u" % (address, eip, size))
        if access == UC_MEM_WRITE_UNMAPPED:
            print("UC_MEM_WRITE_UNMAPPED of 0x%x at 0x%X, data size = %u" % (address, eip, size))
        if access == UC_MEM_FETCH_UNMAPPED:
            print("UC_MEM_FETCH_UNMAPPED of 0x%x at 0x%X, data size = %u" % (address, eip, size))
        if access == UC_MEM_WRITE_PROT:
            print("UC_MEM_WRITE_PROT of 0x%x at 0x%X, data size = %u" % (address, eip, size))
        if access == UC_MEM_FETCH_PROT:
            print("UC_MEM_FETCH_PROT of 0x%x at 0x%X, data size = %u" % (address, eip, size))
        if access == UC_MEM_FETCH_PROT:
            print("UC_MEM_FETCH_PROT of 0x%x at 0x%X, data size = %u" % (address, eip, size))
        if access == UC_MEM_READ_AFTER:
            print("UC_MEM_READ_AFTER of 0x%x at 0x%X, data size = %u" % (address, eip, size))
        return False
    
    
    def find_main_address(self):
        """
        Find the address of the 'main' function in an ELF binary.

        Args:
            data (bytes): The binary ELF file as a byte array.

        Returns:
            int: The address of the 'main' function, or None if not found.
        """
        # Open the ELF file from a binary stream
        elffile = ELFFile(BytesIO(self.program))

        # Get the symbol table
        symtab = None
        for section in elffile.iter_sections():
            if section.name == ".symtab":
                symtab = section
                break

        if not symtab:
            raise ValueError("No symbol table (.symtab) found in the ELF file")

        # Look for the 'main' symbol
        for symbol in symtab.iter_symbols():
            if symbol.name == "main":
                main_offset = symbol.entry.st_value
                main_size = symbol.entry.st_size

                return main_offset + self.code_base, symbol.entry.st_size

        return None, None



    def run_program(self):
        main_address, main_size = self.find_main_address()

        # Until is not clearly defined yet, it depends how many function are called in between
        self.mu.emu_start(main_address, main_address + 500)




# Main function
def main():
    data = open("sample-program", "rb").read()
    tt = InitUnicorn(data, bit=64, debug=True)
    
    try:
        tt.run_program()
        r_eip = tt.mu.reg_read(UC_X86_REG_EIP)
        print("0x%x" % r_eip)
    
    except Exception as e:
        print("ESP 0x%x" % (tt.mu.reg_read(UC_X86_REG_ESP)))
        print("EIP 0x%x" % (tt.mu.reg_read(UC_X86_REG_EIP)))
        print(e)


if __name__ == "__main__":
    main()

