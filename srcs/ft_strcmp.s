section .text
	global _ft_strcmp

_ft_strcmp:
	mov rcx, 0
	mov rax, 0
.loop:
	mov dl, byte [rsi + rax]
	cmp byte [rdi + rcx], dl
	jne .ret
	cmp byte [rdi + rcx], 0
	je .ret
	cmp dl, 0
	je .ret
	inc rcx
	inc rax
	jmp .loop
.ret:
	mov eax, 0
	mov al, byte [rdi + rcx]
	sub al, dl
	ret
