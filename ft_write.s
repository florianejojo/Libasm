

                global	_ft_write
                extern ___error

                segment	.text
                ;ft_write (rdi, rsi, rdx)
_ft_write:
            
	mov	rax, 0x2000004  ; On ajoute 0x200000 au numéro système call correspondant
	syscall                 ; On appelle la fonction du système corerespondant à rax
        jc      error           ; Jump conditionnel en cas d'erreur
        jmp     return          ;  
			
error:
        push rax            ; On écrit la valeur de rax dans la stack, et on décrémente de la taille de rax, puis on call
	call ___error       ; Seulement une fois qu'on a push, et la valeur de l'erreur est stockée dans rax
	pop qword[rax]      ; On récupère ce qu'on a mis dans la stack, et on incrémente dans la mémoire
	mov rax, -1         ; lib.c write return -1 if the write failed
    
return:
           ret                ; return 
    

