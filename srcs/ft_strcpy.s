section .text
	global _ft_strcpy

_ft_strcpy:
	mov rcx, 0
	mov rax, rdi
.loop:
	mov dl, byte [rsi + rcx]
	cmp dl, 0
	je .ret
	mov byte [rdi], dl
	inc rcx
	inc rdi
	jmp .loop
.ret:
	ret
