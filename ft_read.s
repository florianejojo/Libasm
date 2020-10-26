

		global	ft_read
		extern __errno_location
		
		segment	.text

ft_read:
		mov	rax, 0  			; 
		syscall                 ; On appelle la fonction du système correspondant à rax
		cmp rax, 0
		jl error		    	; conditional jump, si le syscall a une retenue (donc une erreur)
		ret		    			; 

error:
		neg rax
		mov r8, rax
		call __errno_location 	; return l'adresse de errno dans rax
		mov [rax], r8           ; on mets le  numéro de l'erreur dans errno
		mov rax, -1         	; 
		ret
                
