

                global	ft_read
                ;extern ___error
				__errno_location
                
                segment	.text

    ft_read:
			mov		rax, 0  ; On ajoute 0x200000 au numéro système call correspondant pou OS 3
			syscall                 ; On appelle la fonction du système correspondant à rax
			jc      error		    ; conditional jump, si le syscall a une retenue (donc une erreur)
	        jmp     return		    ; 

    error:
            push rax            ; On écrit la valeur de rax dans la stack, et on décrémente de la taille de rax, puis on call
	        ;call ___error       ; Seulement une fois qu'on a push, la valeur de l'erreur est stockée dans rax
			call __errno_location
	        pop qword[rax]      ; On récupère ce qu'on a mis dans la stack, et on incrémente dans la mémoire
	        mov 	rax, -1			; on défini la valeur de retour en cas d'erreur
	
    return:
	        ret						; return
                
