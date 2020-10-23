    global _ft_strdup
    extern _ft_strlen
	extern _malloc
	extern _ft_strcpy
    
    segment .text


_ft_strdup:
	call	_ft_strlen		; rdi = chaine à dupliquer | on envoie rdi  dans ft_strlen
	inc		rax				; ret strlen dans rax | + 1 pour 0
	push	rdi				; On save rdi dans la stack | qui est la chaine à duppliquer
	mov		rdi, rax		; on libère rax pour avoir le ret de malloc | rdi = rax = len + 1
	call	_malloc			; On envoie rdi = rax dans malloc | len + 1
	pop		rsi				; On récupère ce qu'on a push dans la stack dans rsi | rsi = chaine à duppliquer
	mov		rdi, rax		; rdi = rax = chaine malloquée 
	call	_ft_strcpy		; call ft_strcpy (rdi, rsi), ret is stock in rax donc la chaine duppliquée
	ret						; return rax so the new string

