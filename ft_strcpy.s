    global _ft_strcpy
    extern _ft_strlen
    
    segment .text
    
_ft_strcpy:
    push 	rdi			        ; on push rdi en haut de la pile
	mov 	rdi, rsi	        ; pour que ce soit rsi envoyé dans strlen (car c'est rdi)
	call 	_ft_strlen 	        ; ret dans rax
	pop 	rdi	                ; on récup ce qu'il y a en haut de la pile dans rdi
    mov     Byte[rdi + rax], 0  ;
    
copy:
    dec     rax
    cmp     rax, 0
    jl      return              ;
	mov	r8, [rsi + rax]		    ; equivalent a  push    qword[rsi + rax]
	mov 	[rdi + rax], r8		;               pop     qword[rdi + rax]
    loop    copy                ;

return:
	mov		rax, rdi			; on return rax
	ret

