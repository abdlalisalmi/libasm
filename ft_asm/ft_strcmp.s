


  
section .text
	global _ft_strcmp

_ft_strcmp:
	xor 	rax, rax		; define rax to 0
	jmp		_compare		; call compa

_compare:
	mov		al, BYTE [rdi]	; store one byte (char) in al register from arg0 in rdi
	mov		bl, BYTE [rsi]	; store one byte (char) in bl register from arg1 in rsi

	cmp		al, 0			; check if we are at the end of rdi (arg0)
	je		_exit			; if yes, jump to exit

	cmp		bl, 0			; check if we are at the end of rdi (arg1)
	je		_exit			; if yes, jump to exit

	cmp 	al, bl			; compare al and bl
	jne 	_exit			; if the result of cmp is not equal 0 so the strings are differents

	inc 	rdi				; increment the rdi pointer
	inc 	rsi				; increment the rsi pointer
	jmp 	_compare		; if we are here it's because the chars of string are equals the we can continu

_exit:
	movzx	rax, al			; movzx ==> copy a register of inferior size in a bigger and fill the other bits with 0.
    movzx	rbx, bl			; same that previous but set it in rbx
    sub		rax, rbx		; stock the difference of rax and rbx in rax
	ret						; return (rax)