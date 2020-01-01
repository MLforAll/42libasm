section .text
	global _ft_strlen

_ft_strlen:
	mov rcx, 0
.loop:
	inc rcx
	cmp byte [rdi + rcx], 0
	jne .loop
	mov rax, rcx
	ret
