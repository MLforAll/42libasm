section .text
	global _ft_strcmp

_ft_strcmp:
	push rbp
	mov rbp, rsp
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
	movzx eax, byte [rdi]
	movzx edx, dl
	sub eax, edx
	mov rsp, rbp
	pop rbp
	ret
