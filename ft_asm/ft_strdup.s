



section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc


_ft_strdup:                 ; ft_strdup(const char rdi).
	call	_ft_strlen		; call ft_strlen to have the len of arg0 and save it in rax.
	add		rax, 1			; add one to rax for '\0'.

	push	rdi				; save value of rdi (arg0) in stack.
	mov		rdi, rax		; set len at rdi (arg0) for malloc.
	call	_malloc			; call malloc, return in rax

	pop		r9				; get arg0 (the origin string) stocked on stack
	mov		rdi, rax		; set the string malloced in rax to rdi (arg0) for ft_strcpy
	mov		rsi, r9			; get arg0 stocked in r9 on rsi (arg0) for ft_strcpy
	call	_ft_strcpy		; call ft_strcpy(rdi = dest, rsi = src), return is stocked in rax

	ret						; return rax (the new string)
