




section .text
	global _ft_strcpy
	extern _ft_strlen	; call ft_strlen


_ft_strcpy:             ; ft_strcpy(arg0 = rdi = dst, arg1 = rsi = src)

	push 	rdi			    ; to save it on the top of the stack
	mov 	rdi, rsi	    ; move rsi dans rdi

	call 	_ft_strlen 	    ; call ft_strlen, result is stock in rax

	mov 	rcx, rax	    ; move rax dans rcx because rcx used by rep after

	pop 	rdi			    ; get rdi from the top of the stack

	mov 	rax, rdi	    ; set return is the first adresse of rdi

	cld					    ; clear flag DF, DF = 0 = increment for rep, DF = 1 = decrement for rep
	rep 	movsb			; movsb get string from rsi and set it to rdi at rep, rep incres automaticaly until rsi on movsb is'nt 0 
	mov 	BYTE [rdi], 0	; rdi was increse by movsb, so we are at end of the copied string

	ret					    ; return rax
