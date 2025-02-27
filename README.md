# Chall - Unoptimus Prime
> In this challenge, participants must compile a program that does a certain task. However, no prime numbers should ever get in the registers (either per byte, in hex, or in dec), as well as in opcodes.

## Type

- [ ] **OFF**line
- [X] **ON**line

## Designer(s)

- Hugo Kermabon-Bobinnec
- Anis Lounis (for helping with the idea)

## Description

The challenge deals with the binary-level skills of participants. On the x86-64 platform, program are compiled into binary executables, which contains instructions for the CPU to run.
However, in our case, participants cannot use prime numbers in the binary code they produce. This is a very annoying constraint since the most used instruction (mov rax/eax/etc.) start with the opcode "0x89" which is prime.
The constraint regarding other prime numbers should be less annoying, but can be lifted if needed (89 is prime both in dec, but 0x89 in dec (137) is also prime).
Participants have to find other ways to achieve their goal than using regular mov instructions, but it also applies to the values they store in registers etc.

Notes:
0x89 is mov, 89 is prime, 137 as well (0x89 = 137)
0x97 is prime both in hex and in dec (151)
0x83 as well (131)



## Category(ies)

- `re`