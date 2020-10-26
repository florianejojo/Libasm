

        global	ft_write
        extern __errno_location

        segment	.text

ft_write:
            
	mov rax, 1      ; Pour appeler write
	syscall         ; On appelle la fonction du système corerespondant à rax
        cmp rax, 0      ; si c'est neg c'est une erreur
        jl error        ; Jump conditionnel en cas d'erreur
        ret

			
error:

        neg rax
        mov r8, rax
        call __errno_location ; va return l'adresse de errno dans rax
        mov [rax], r8         ; on mets le  numéro de l'erreur dans errno
	mov rax, -1           ; lib.c write return -1 if the write failed
        ret

    

