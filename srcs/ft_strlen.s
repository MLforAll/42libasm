section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je .ret
	mov rcx, 0
.loop:
	cmp byte [rdi + rcx], 0
	je .ret
	inc rcx
	jmp .loop
.ret:
	mov rax, rcx
	mov rsp, rbp
	pop rbp
	ret
