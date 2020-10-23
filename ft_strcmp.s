			
	global	ft_strcmp

    segment .text


ft_strcmp:

                cmp		byte[rdi], 0	
	            je		return			
	            cmp		byte[rsi], 0	
	            je		return

                cmp     rdi, rsi 
                jnz     return
                inc     rdi
                inc     rsi
                loop    ft_strcmp

return:
                movzx   rax, byte [rdi]
                movzx   rbx, byte [rsi]
                sub     rax, rbx
                ret
