    global _ft_strcpy
    extern _ft_strlen
    
    segment .text
    
_ft_strcpy:
    push 	rdi			        ; 
	mov 	rdi, rsi	        ; pour que ce soit rsi envoyé dans strlen
	call 	_ft_strlen 	        ; ret dans rax
    mov     rcx, rax            ;
	mov 	rsi, rdi            ; on remet tout en place
	pop 	rdi	                ; on récup rdi
    mov		cl, 0				; 
	mov		[rdi + rcx], cl		; rdi[rax] = 0
    
    
copy:
    dec     rcx
    cmp     rcx, 0
    jl      return              ;
	mov		cl, [rsi + rcx]		; cl = rsi[rax] | copy rsi[rax] to cl
	mov 	[rdi + rcx], cl		; rdi[rax] = cl | copy cl to rdi[rax]
    loop    copy                ;

return:
    
	mov		rax, rdi			; on return rax
	ret