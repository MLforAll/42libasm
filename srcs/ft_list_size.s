section .text
	global _ft_list_size

_ft_list_size:
	push rbp
	mov rbp, rsp
	mov rax, 0
.loop:
	cmp rdi, 0
	je .ret
	inc rax
	mov rdi, qword [rdi + 8]
	jmp .loop
.ret:
	mov rsp, rbp
	pop rbp
	ret
