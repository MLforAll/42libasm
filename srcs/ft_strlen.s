section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp
	mov rax, 0
	cmp rdi, 0
	je .ret
.loop:
	cmp byte [rdi + rax], 0
	je .ret
	inc rax
	jmp .loop
.ret:
	mov rsp, rbp
	pop rbp
	ret
