

                global	ft_strlen
                segment	.text

ft_strlen:
                mov     rax, 0                  ;       

loop:           cmp     Byte[rdi + rax], 0      ; rdi pointe vers le début de la chaine, on ajoute rax pour comparer le char en question avec 0
                je      return                  ;       si comparaison = 0, return rax
                inc     rax                     ;        sinon on incrément rax
                jmp     loop                    ;       et on refait un tour de boucle

return:
                ret                             ;

