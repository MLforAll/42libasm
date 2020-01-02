section .text
	global _ft_strcmp

_ft_strcmp:
.loop:
	mov dl, byte [rsi]
	cmp byte [rdi], dl
	jne .ret
	cmp byte [rdi], 0
	je .ret
	cmp dl, 0
	je .ret
	inc rdi
	inc rsi
	jmp .loop
.ret:
	mov eax, 0
	mov al, byte [rdi]
	sub al, dl
	movsx eax, al
	ret
