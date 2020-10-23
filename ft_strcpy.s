    global _ft_strcpy
    extern _ft_strlen
    
    segment .text
    
_ft_strcpy:
    push 	rdi			        ; 
	mov 	rdi, rsi	        ; pour que ce soit rsi envoyé dans strlen (car c'est rdi)
	call 	_ft_strlen 	        ; ret dans rax
    ;mov     rcx, rax            ;
	mov 	rsi, rdi            ; on remet tout en place
	pop 	rdi	                ; on récup rdi
    mov		r8, 0				; 
	mov		[rdi + rax], r8		; rdi[rax] = 0
    
copy:
    dec     rax
    cmp     rax, 0
    jl      return              ;
	mov		r8, [rsi + rax]		;
	mov 	[rdi + rax], r8		; 
    loop    copy                ;

return:
	mov		rax, rdi			; on return rax
	ret

