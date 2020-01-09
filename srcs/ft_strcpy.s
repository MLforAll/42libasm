section .text
	global _ft_strcpy

_ft_strcpy:
	push rbp
	mov rbp, rsp
	mov rax, rdi
.loop:
	mov dl, byte [rsi]
	cmp dl, 0
	je .ret
	mov byte [rdi], dl
	inc rsi
	inc rdi
	jmp .loop
.ret:
	mov byte [rdi], 0
	mov rsp, rbp
	pop rbp
	ret
