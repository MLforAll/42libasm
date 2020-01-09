section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov qword [rbp - 8], rdi
	call _ft_strlen
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je .ret
	mov rdi, rax
	mov rsi, qword [rbp - 8]
	call _ft_strcpy
.ret:
	mov rsp, rbp
	pop rbp
	ret
