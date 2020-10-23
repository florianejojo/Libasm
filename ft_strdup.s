    global ft_strdup
    extern ft_strlen
	extern malloc
	extern ft_strcpy
    
    segment .text


ft_strdup:
	call	ft_strlen		; rdi = chaine à dupliquer | on envoie rdi  dans ft_strlen
	inc		rax				; ret strlen dans rax | + 1 pour 0
	push	rdi				; On save rdi dans la stack | qui est la chaine à duppliquer
	mov		rdi, rax		; on libère rax pour avoir le ret de malloc | rdi = rax = len + 1
	call	malloc			; On envoie rdi = rax dans malloc | len + 1
	pop		rsi				; On récupère ce qu'on a push dans la stack dans rsi | rsi = chaine à duppliquer
	mov		rdi, rax		; rdi = rax = chaine malloquée 
	call	ft_strcpy		; ft_strcpy (rdi, rsi) | chaine duppliquée = rax
	ret						;

