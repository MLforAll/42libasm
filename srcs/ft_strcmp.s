section .text
	global _ft_strcmp

_ft_strcmp:
	push rbp
	mov rbp, rsp
	mov eax, 0
	cmp rdi, 0
	je .ft_ret
.ft_loop:
	mov dl, byte [rsi]
	cmp byte [rdi], dl
	jne .finish
	cmp byte [rdi], 0
	je .finish
	cmp dl, 0
	je .finish
	inc rdi
	inc rsi
	jmp .ft_loop
.finish:
	movzx eax, byte [rdi]
	movzx edx, dl
	sub eax, edx
.ft_ret:
	mov rsp, rbp
	pop rbp
	ret
