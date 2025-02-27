`objdump -d ../solver/sample-program-O0-asm-noprime`

0000000000001159 <main>:
    1159:       55                      push   %rbp
    115a:       48 89 e5                mov    %rsp,%rbp
    115d:       48 83 ec 20             sub    $0x20,%rsp
    1161:       89 7d ec                mov    %edi,-0x14(%rbp)
    1164:       48 89 75 e0             mov    %rsi,-0x20(%rbp)
    1168:       48 83 ec 20             sub    $0x20,%rsp
    116c:       90                      nop
    116d:       ff 75 e0                push   -0x20(%rbp)
    1170:       58                      pop    %rax
    1171:       48 83 c0 08             add    $0x8,%rax
    1175:       ff 30                   push   (%rax)
    1177:       58                      pop    %rax
    1178:       50                      push   %rax
    1179:       5f                      pop    %rdi
    117a:       e8 c1 fe ff ff          call   1040 <atoi@plt>
    117f:       50                      push   %rax
    1180:       8f 45 fc                pop    -0x4(%rbp)
    1183:       90                      nop
    1184:       ff 75 e0                push   -0x20(%rbp)
    1187:       58                      pop    %rax
    1188:       48 83 c0 10             add    $0x10,%rax
    118c:       ff 30                   push   (%rax)
    118e:       58                      pop    %rax
    118f:       50                      push   %rax
    1190:       5f                      pop    %rdi
    1191:       e8 aa fe ff ff          call   1040 <atoi@plt>
    1196:       89 45 f8                mov    %eax,-0x8(%rbp)
    1199:       90                      nop
    119a:       48 8b 45 e0             mov    -0x20(%rbp),%rax
    119e:       48 83 c0 18             add    $0x18,%rax
    11a2:       ff 30                   push   (%rax)
    11a4:       58                      pop    %rax
    11a5:       50                      push   %rax
    11a6:       5f                      pop    %rdi
    11a7:       e8 94 fe ff ff          call   1040 <atoi@plt>
    11ac:       89 45 f4                mov    %eax,-0xc(%rbp)
    11af:       90                      nop
    11b0:       8b 55 fc                mov    -0x4(%rbp),%edx
    11b3:       8b 45 f8                mov    -0x8(%rbp),%eax
    11b6:       01 c2                   add    %eax,%edx
    11b8:       8b 45 f4                mov    -0xc(%rbp),%eax
    11bb:       01 d0                   add    %edx,%eax
    11bd:       89 45 f0                mov    %eax,-0x10(%rbp)
    11c0:       90                      nop
    11c1:       8b 45 f0                mov    -0x10(%rbp),%eax
    11c4:       89 c6                   mov    %eax,%esi
    11c6:       48 8d 05 37 0e 00 00    lea    0xe37(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    11cd:       50                      push   %rax
    11ce:       5f                      pop    %rdi
    11cf:       b8 00 00 00 00          mov    $0x0,%eax
    11d4:       e8 57 fe ff ff          call   1030 <printf@plt>
    11d9:       90                      nop
    11da:       bf 00 00 00 00          mov    $0x0,%edi
    11df:       e8 6c fe ff ff          call   1050 <exit@plt>