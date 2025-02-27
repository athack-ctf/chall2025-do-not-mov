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
        "call   atoi\n"
        // "mov    DWORD PTR [rbp-0x4],eax\n"
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
        "call   atoi\n"
        "mov    DWORD PTR [rbp-0x8],eax\n"
        "nop\n"
        "mov    rax,QWORD PTR [rbp-0x20]\n"
        "add    rax,0x18\n"
        // "mov    rax,QWORD PTR [rax]\n"
        "push [rax]\n"
        "pop rax\n"
        //
        // "mov    rdi,rax\n"
        "push rax\n"
        "pop rdi\n"
        //
        "call   atoi\n"
        "mov    DWORD PTR [rbp-0xc],eax\n"
        "nop\n"
        "mov    edx,DWORD PTR [rbp-0x4]\n"
        "mov    eax,DWORD PTR [rbp-0x8]\n"
        "add    edx,eax\n"
        "mov    eax,DWORD PTR [rbp-0xc]\n"
        "add    eax,edx\n"
        "mov    DWORD PTR [rbp-0x10],eax\n"
        "nop\n"
        "mov    eax,DWORD PTR [rbp-0x10]\n"
        "mov    esi,eax\n"
        "lea    rax,[rip+0xe37]\n"
        // "mov    rdi,rax\n"
        "push rax\n"
        "pop rdi\n"
        //
        "mov    eax,0x0\n"
        "call   printf\n"
        // "nop\n"
        // "mov    eax,0x0\n"
        // "leave\n"
        // "ret\n"
        );

    exit(0);
}



