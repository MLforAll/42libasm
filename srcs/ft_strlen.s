section .text
	global _ft_strlen

_ft_strlen:
	mov rcx, 0
.loop:
	cmp byte [rdi + rcx], 0
	je .ret
	inc rcx
	jmp .loop
.ret:
	mov rax, rcx
	ret
