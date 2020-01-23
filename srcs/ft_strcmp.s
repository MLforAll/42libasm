section .text
	global _ft_strcmp

_ft_strcmp:
	push rbp
	mov rbp, rsp

	mov eax, 0

	cmp rdi, 0
	jne .s1_notnull
	cmp rsi, 0
	je .ret
	movsx eax, byte [rsi]
	neg eax
	jmp .ret
.s1_notnull:
	cmp rsi, 0
	jne .loop
	movsx eax, byte [rdi]
	jmp .ret

.loop:
	mov dh, byte [rdi]
	mov dl, byte [rsi]
	cmp dh, dl
	jne .finish
	cmp dh, 0
	je .finish
	cmp dl, 0
	je .finish
	inc rdi
	inc rsi
	jmp .loop
.finish:
	movzx eax, dh
	movzx edx, dl
	sub eax, edx
.ret:
	mov rsp, rbp
	pop rbp
	ret
