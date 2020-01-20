section .text
	global _ft_strcpy

_ft_strcpy:
	push rbp
	mov rbp, rsp
	mov rax, rdi
	cmp rdi, 0
	je .ft_ret
.ft_loop:
	mov dl, byte [rsi]
	cmp dl, 0
	je .finish
	mov byte [rdi], dl
	inc rsi
	inc rdi
	jmp .ft_loop
.finish:
	mov byte [rdi], 0
.ft_ret:
	mov rsp, rbp
	pop rbp
	ret
