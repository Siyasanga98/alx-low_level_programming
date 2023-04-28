section .data
    msg db 'Hello, Holberton', 0x0a, 0x00

section .text
    global main

main:
    mov rax, 0
    lea rdi, [msg]
    call printf
    mov rax, 0
    ret
