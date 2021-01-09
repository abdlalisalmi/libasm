



section .text
    global _ft_read
	extern ___error

_ft_read:                       ; ft_read (fd = rdi, buffer = rsi, bytes = rdx)
	mov 	rax, 0x2000003	    ; set call to read
	syscall					    ; call rax (read)
		jc _error		        ; if doesn't work, read set flags carry to 1 so jmp exit error
	ret						    ; return 

_error:
	push rax        			; save errno
    call ___error   			; rax is now points to external variable errno.
    pop qword[rax]  			; The QWORD PTR is just a size specifier (It means that a 64 bit value is read from the address)
	mov 	rax, -1			    ; set rax to -1
	ret						    ; return rax (-1)