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
The constraint regarding other prime numbers should be less annoying, but can be lifted if needed (89 is prime both in dec, but 0x89 in dec (137) is also prime)).
Participants have to find other ways to achieve their goal than using regular mov instructions, but it also applies to the values they store in registers etc.


## Category(ies)

- `re`

---

# Project Structure

## 1. HACKME.md

- **[HACKME.md](HACKME.md)**: A teaser or description of the challenge to be shared with participants (in CTFd).

## 2. Source Code

- **[source/README.md](source/README.md)**: Comprehensive instructions on how to have a running instance of your
  challenge from the source.
  If your project includes multiple subprojects, please consult us (Anis and Hugo).
- **[source/*](source/)**: Your source code.

## 3. Offline Artifacts [OPTIONAL]

> **NOTE:** This directory is optional for online challenges. However, if offline artifacts need to be provided as well, 
> they should be placed here.

- **[offline-artifacts/*](offline-artifacts/)**: All files intended to be downloaded by participants
  (e.g., a flagless version of the running binary executable of a pwn challenge).
  For large files (exceeding 100 MB), please consult us (Anis and Hugo).

## 4. Solution

- **[solution/README.md](solution/README.md)**: A detailed writeup of the working solution.
- **[solution/FLAGS.md](solution/FLAGS.md)**: A single markdown file listing all (up-to-date) flags.
- **[solution/*](solution/)**: Any additional files or code necessary for constructing a reproducible solution for the
  challenge (e.g., `PoC.py`, `requirement.txt`, etc.).

## 5. Dockerization

> **NOTE:** For deployment on @Hack's infrastructure, online challenges must be containerized.
> However, this requirement does not apply during the early stages of challenge development, so do not hesitate to start
> building your online challenge if you are unfamiliar with containerization.
> We (Anis and Hugo) will take care of it.

- **[source/Dockerfile](source/Dockerfile)**: Needed for building a containerized image of the online challenge.
- **[source/docker-compose.yml](source/docker-compose.yml)**: Needed for a configuration-free run of the online
  challenge
