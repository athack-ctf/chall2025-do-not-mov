#include <stdio.h>
#include <stdlib.h>

char* rostring = "Sum: %d\n";


int main(int argc, char* argv[]) {
    // Convert arguments to integers
    volatile int num1;
    volatile int num2;
    volatile int num3;
    volatile int sum;

    asm volatile (
        "sub    rsp,0x20\n"
        "nop\n"


        // "mov    rax,[rbp-0x20]\n"
        "push [rbp-0x20]\n"
        "pop rax\n"
        //
        "add    rax,0x8;\n"
        // "mov    rax,[rax]\n"
        "push [rax]\n"
        "pop rax\n"
        //
        // "mov    rdi,rax\n"
        "push rax\n"
        "pop rdi\n"
        //
        //
        "call   atoll\n"
        // "mov    QWORD PTR [rbp-0x4],rax\n"
        "push rax\n"
        "pop [rbp-0x4]\n"
        //
        "nop\n"






        // "mov    rax,QWORD PTR [rbp-0x20]\n"
        "push [rbp-0x20]\n"
        "pop rax\n"        
        //
        "add    rax,0x10\n"
        // "mov    rax,QWORD PTR [rax]\n"
        "push [rax]\n"
        "pop rax\n"
        //
        // "mov    rdi,rax\n"
        "push rax\n"
        "pop rdi\n"
        //
        "call   atoll\n"
        // "mov    QWORD PTR [rbp-0xc],rax\n"
        "push rax\n"
        "pop [rbp-0xc]\n"
        //
        "nop\n"





        // "mov    rax,QWORD PTR [rbp-0x20]\n"
        "push [rbp-0x20]\n"
        "pop rax\n"         
        "add    rax,0x18\n"
        // "mov    rax,QWORD PTR [rax]\n"
        "push [rax]\n"
        "pop rax\n"
        //
        // "mov    rdi,rax\n"
        "push rax\n"
        "pop rdi\n"
        //
        "call   atoll\n"
        // "mov    QWORD PTR [rbp-0x14],rax\n"
        "push rax\n"
        "pop [rbp-0x14]\n"
        //
        "nop\n"





        // "mov    rdx,QWORD PTR [rbp-0x4]\n"
        "push   [rbp-0x4]\n"
        "pop    rdx\n"

        // "mov    rax,QWORD PTR [rbp-0xc]\n"
        "push   [rbp-0xc]\n"
        "pop    rax\n"

        "add    rdx,rax\n"
        // "mov    rax,QWORD PTR [rbp-0x14]\n"
        "push   [rbp-0x14]\n"
        "pop    rax\n"

        "add    rax,rdx\n"
        // "mov    QWORD PTR [rbp-0x10],rax\n"
        "push   rax\n"
        "pop    [rbp-0x10]\n"

        "nop\n"
        // "mov    rax,QWORD PTR [rbp-0x10]\n"
        "push   [rbp-0x10]\n"
        "pop    rax\n"

        // Allow this one
        "mov    rsi,rax\n"

        "lea    rax,[rip+0xe2d]\n"
        // "mov    rdi,rax\n"
        "push rax\n"
        "pop rdi\n"
        //
        // "mov    rax,0x0\n"
        "xor rax,rax\n"

        "call   printf\n"
        // "nop\n"
        // "mov    eax,0x0\n"
        // "leave\n"
        // "ret\n"

        // EXIT
        // "xor edi,edi\n"
        // "call exit\n"
        );

    exit(0);
}



