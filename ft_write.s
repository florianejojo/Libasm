

                global	_ft_write
                
                segment	.text

    _ft_write:
			mov		rax, 0x2000004  ; On ajoute 0x200000 au numéro système call correspondant
			syscall                 ; 
			ret
                
