

                global	_ft_read
                
                segment	.text
;ssize_t read(int fd, void *buf, size_t count);
;pareil pour write (fd, *buf, count);

    _ft_read:
			mov		rax, 0x2000003  ; On ajoute 0x200000 au numéro système call correspondant
			syscall                 ; 
			ret
                
