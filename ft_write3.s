global	_ft_write
                extern ___error

                segment	.text



_ft_write:	; entry-point of the file
		mov rax, 0x2000004	; syscall number to call syswrite
		syscall				; call write will take the 3 first inputed args
		jc error			; CF (carry flag) is set upon when syscall failed
		ret					; return is already put in the rax reg by syswrite

error:
	push rax
	call ___error
	pop qword[rax]
	mov rax, -1; lib.c write return -1 if the write failed
	ret