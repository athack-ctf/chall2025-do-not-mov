`gcc -O0 -masm=intel sample-program-asm.c -o sample-program-O0-asm`

1) First I construct a base, I get the assembly code, then I rewrite an entire function in asm.


Original code:






0000000000001149 <main>:
    1149:       55                      push   rbp
    114a:       48 89 e5                mov    rbp,rsp
    114d:       48 83 ec 20             sub    rsp,0x20
    1151:       89 7d ec                mov    DWORD PTR [rbp-0x14],edi
    1154:       48 89 75 e0             mov    QWORD PTR [rbp-0x20],rsi
    1158:       90                      nop
    1159:       90                      nop
    115a:       90                      nop
    115b:       90                      nop
    115c:       90                      nop
    115d:       90                      nop
    115e:       90                      nop
    115f:       48 8b 45 e0             mov    rax,QWORD PTR [rbp-0x20]
    1163:       48 83 c0 08             add    rax,0x8
    1167:       48 8b 00                mov    rax,QWORD PTR [rax]
    116a:       48 89 c7                mov    rdi,rax
    116d:       e8 ce fe ff ff          call   1040 <atoi@plt>
    1172:       89 45 fc                mov    DWORD PTR [rbp-0x4],eax
    1175:       90                      nop
    1176:       90                      nop
    1177:       90                      nop
    1178:       90                      nop
    1179:       90                      nop
    117a:       90                      nop
    117b:       90                      nop
    117c:       48 8b 45 e0             mov    rax,QWORD PTR [rbp-0x20]
    1180:       48 83 c0 10             add    rax,0x10
    1184:       48 8b 00                mov    rax,QWORD PTR [rax]
    1187:       48 89 c7                mov    rdi,rax
    118a:       e8 b1 fe ff ff          call   1040 <atoi@plt>
    118f:       89 45 f8                mov    DWORD PTR [rbp-0x8],eax
    1192:       90                      nop
    1193:       90                      nop
    1194:       90                      nop
    1195:       90                      nop
    1196:       90                      nop
    1197:       90                      nop
    1198:       90                      nop
    1199:       48 8b 45 e0             mov    rax,QWORD PTR [rbp-0x20]
    119d:       48 83 c0 18             add    rax,0x18
    11a1:       48 8b 00                mov    rax,QWORD PTR [rax]
    11a4:       48 89 c7                mov    rdi,rax
    11a7:       e8 94 fe ff ff          call   1040 <atoi@plt>
    11ac:       89 45 f4                mov    DWORD PTR [rbp-0xc],eax
    11af:       90                      nop
    11b0:       90                      nop
    11b1:       90                      nop
    11b2:       90                      nop
    11b3:       90                      nop
    11b4:       90                      nop
    11b5:       90                      nop
    11b6:       8b 55 fc                mov    edx,DWORD PTR [rbp-0x4]
    11b9:       8b 45 f8                mov    eax,DWORD PTR [rbp-0x8]
    11bc:       01 c2                   add    edx,eax
    11be:       8b 45 f4                mov    eax,DWORD PTR [rbp-0xc]
    11c1:       01 d0                   add    eax,edx
    11c3:       89 45 f0                mov    DWORD PTR [rbp-0x10],eax
    11c6:       90                      nop
    11c7:       90                      nop
    11c8:       90                      nop
    11c9:       90                      nop
    11ca:       90                      nop
    11cb:       90                      nop
    11cc:       90                      nop
    11cd:       8b 45 f0                mov    eax,DWORD PTR [rbp-0x10]
    11d0:       89 c6                   mov    esi,eax
    11d2:       48 8d 05 2b 0e 00 00    lea    rax,[rip+0xe2b]        # 2004 <_IO_stdin_used+0x4>
    11d9:       48 89 c7                mov    rdi,rax
    11dc:       b8 00 00 00 00          mov    eax,0x0
    11e1:       e8 4a fe ff ff          call   1030 <printf@plt>
    11e6:       90                      nop
    11e7:       90                      nop
    11e8:       90                      nop
    11e9:       90                      nop
    11ea:       90                      nop
    11eb:       90                      nop
    11ec:       90                      nop
    11ed:       b8 00 00 00 00          mov    eax,0x0
    11f2:       c9                      leave
    11f3:       c3                      ret






2) The asm version has a few changes:
- char* rostring = "Sum: %d\n"; must be added as global to simulate the presence of the args for print.
- In addition, the value inside lea    rax,[rip+0xe2b]        # 2004 <-- the "Sum: %d" string
must be manually offseted until it falls on 2004.
- Parameters are declared as volatile, otherwise they'll be ignored (unused), also stack size must be build manually by adding         "sub    rsp,0x20\n"
- Finally, I replace the "return 0" with an "exit(0)" to avoid a segfault when returning (can be avoided)

Eventually I get a version that compiles and work. We can also manually add NOPs to make our life easier when rewriting. Now we need to remove the primes.


0000000000001159 <main>:
    1159:       55                      push   rbp
    115a:       48 89 e5                mov    rbp,rsp
    115d:       48 83 ec 20             sub    rsp,0x20
    1161:       89 7d ec                mov    DWORD PTR [rbp-0x14],edi
    1164:       48 89 75 e0             mov    QWORD PTR [rbp-0x20],rsi
    1168:       48 83 ec 20             sub    rsp,0x20
    116c:       90                      nop
    116d:       48 8b 45 e0             mov    rax,QWORD PTR [rbp-0x20]
    1171:       48 83 c0 08             add    rax,0x8
    1175:       48 8b 00                mov    rax,QWORD PTR [rax]
    1178:       48 89 c7                mov    rdi,rax
    117b:       e8 c0 fe ff ff          call   1040 <atoi@plt>
    1180:       89 45 fc                mov    DWORD PTR [rbp-0x4],eax
    1183:       90                      nop
    1184:       48 8b 45 e0             mov    rax,QWORD PTR [rbp-0x20]
    1188:       48 83 c0 10             add    rax,0x10
    118c:       48 8b 00                mov    rax,QWORD PTR [rax]
    118f:       48 89 c7                mov    rdi,rax
    1192:       e8 a9 fe ff ff          call   1040 <atoi@plt>
    1197:       89 45 f8                mov    DWORD PTR [rbp-0x8],eax
    119a:       90                      nop
    119b:       48 8b 45 e0             mov    rax,QWORD PTR [rbp-0x20]
    119f:       48 83 c0 18             add    rax,0x18
    11a3:       48 8b 00                mov    rax,QWORD PTR [rax]
    11a6:       48 89 c7                mov    rdi,rax
    11a9:       e8 92 fe ff ff          call   1040 <atoi@plt>
    11ae:       89 45 f4                mov    DWORD PTR [rbp-0xc],eax
    11b1:       90                      nop
    11b2:       8b 55 fc                mov    edx,DWORD PTR [rbp-0x4]
    11b5:       8b 45 f8                mov    eax,DWORD PTR [rbp-0x8]
    11b8:       01 c2                   add    edx,eax
    11ba:       8b 45 f4                mov    eax,DWORD PTR [rbp-0xc]
    11bd:       01 d0                   add    eax,edx
    11bf:       89 45 f0                mov    DWORD PTR [rbp-0x10],eax
    11c2:       90                      nop
    11c3:       8b 45 f0                mov    eax,DWORD PTR [rbp-0x10]
    11c6:       89 c6                   mov    esi,eax
    11c8:       48 8d 05 35 0e 00 00    lea    rax,[rip+0xe35]        # 2004 <_IO_stdin_used+0x4>
    11cf:       48 89 c7                mov    rdi,rax
    11d2:       b8 00 00 00 00          mov    eax,0x0
    11d7:       e8 54 fe ff ff          call   1030 <printf@plt>
    11dc:       90                      nop
    11dd:       bf 00 00 00 00          mov    edi,0x0
    11e2:       e8 69 fe ff ff          call   1050 <exit@plt>







3) Here is a list of problematic instructions:



89:

48 89 e5                mov    rbp,rsp
89 7d ec                mov    DWORD PTR [rbp-0x14],edi
48 89 75 e0             mov    QWORD PTR [rbp-0x20],rsi

89 45 fc                mov    DWORD PTR [rbp-0x4],eax
48 89 c7                mov    rdi,rax
89 45 f0                mov    DWORD PTR [rbp-0x10],eax





c7 (199):

48 89 c7                mov    rdi,rax






2b (43):

48 8d 05 2b 0e 00 00    lea    rax,[rip+0xe2b]        # 2004 <_IO_stdin_used+0x4>






8b (139):

8b 45 f0                mov    eax,DWORD PTR [rbp-0x10]
48 8b 45 e0             mov    rax,QWORD PTR [rbp-0x20]
48 8b 00                mov    rax,QWORD PTR [rax]





83(131):
48 83 ec 20             sub    rsp,0x20
48 83 c0 10             add    rax,0x10
48 83 c0 18             add    rax,0x18






Observation: 

- mov rbp,rsp is the function prologue; it's difficult to change it. We'll either make an exception (say "we'll allow ONE prime to be used ONCE"), or replace it manually at the end.
- By luck, none of the "call" has a prime in it!
- Loading argc and argv is also difficult to change. I dont what to do with this one.


- most others mov can be fixed with push/pop equivalents:
mov eax, ebx -> push ebx, pop eax. We'll need to add nop, and push and pop can take more space.

We rewrite stuff one by one.
Example: 








115a:       48 89 e5                mov    rbp,rsp
115d:       48 83 ec 20             sub    rsp,0x20
1161:       89 7d ec                mov    DWORD PTR [rbp-0x14],edi
1164:       48 89 75 e0             mov    QWORD PTR [rbp-0x20],rsi
1168:       48 83 ec 20             sub    rsp,0x20


1171:       48 83 c0 08             add    rax,0x8





--> FINAL CHANGES

epilogue
replace bf 00 00 00 00          mov    edi,0x0
with    31 ff 90 90 90          xor    edi,edi   NOP NOP NOP


prologue
    115a:       48 89 e5                mov    rbp,rsp
    115d:       48 83 ec 20             sub    rsp,0x20
    1161:       89 7d ec                mov    DWORD PTR [rbp-0x14],edi
    1164:       48 89 75 e0             mov    QWORD PTR [rbp-0x20],rsi
