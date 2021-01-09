



section .text
    global _ft_write
    extern ___error

_ft_write:                          ; fd = rdi, buffer = rsi, bytes = rdx
    mov     rax, 0x2000004          ; set call to write
    syscall
    jc     _error
    ret
_error:
    push rax        ; save errno
    call ___error   ; rax is now points to external variable errno.
    pop qword[rax]  ; The QWORD PTR is just a size specifier (It means that a 64 bit value is read from the address)
    mov rax, -1
    ret