# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 17:06:09 by flolefeb          #+#    #+#              #
#    Updated: 2020/10/15 17:06:18 by flolefeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

                global	_ft_strlen
                
                segment	.text
    
_ft_strlen:
                mov     rax, 0  ;       on initisalise le compteur de boucle

loop:           cmp     Byte[rdi + rax], 0   ; rdi pointe vers le début de la chaine, on ajoute rax pour comparer le char en question avec 0
                je      return      ;       si comparaison = 0, return rax
                inc     rax          ;        sinon on incrément rax
                jmp     loop            ;       et on refait un tour de boucle


return:
                ret              ;

                