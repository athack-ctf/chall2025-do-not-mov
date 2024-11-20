from qiling import Qiling
from qiling.const import QL_VERBOSE
# from qiling.os.const import INDEX_sys_write



def get_binary_range(ql):
    """
    Get the memory range where the binary is loaded.
    """

    print("\n".join(ql.mem.get_formatted_mapinfo()))

    for map in ql.mem.get_mapinfo():
        if ((map[3] in binary_path) and ('x' in map[2])):
            start_addr, end_addr = map[0], map[1]
            return start_addr, end_addr
    return None, None


def check_prime_opcode(opcode):
    print("Opcode: ", opcode.hex())
    return False

def check_prime_reg(regs):
    regs_values = [f"  {REG_NAME}: {hex(regs.read(REG_NAME))}" for REG_NAME in ["EAX", "EBX", "ECX"]]

    print("Regs:\n", "\n".join(regs_values))

    return False



def hook_instruction(ql, address, size):
    """
    Hook each instruction for debugging or custom checks.
    """
    if binary_start <= address < binary_end:
        # Read the current instruction
        opcode = ql.mem.read(address, size)
        regs = ql.arch.regs

        check_prime_opcode(opcode)
        check_prime_reg(regs)



def main():
    # Path to your binary
    global binary_path
    binary_path = "./sample-program"  # Replace with your ELF binary path

    # Create a Qiling instance with rootfs
    ql = Qiling([binary_path], "./rootfs/x8664_linux_glibc2.39", verbose=QL_VERBOSE.DISABLED)

    global binary_start, binary_end
    binary_start, binary_end = get_binary_range(ql)
    print(binary_start, binary_end)

    # Hook instructions
    ql.hook_code(hook_instruction)

    # Start the emulation
    ql.run()


if __name__ == "__main__":
    main()
