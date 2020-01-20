section .text
	global _ft_list_sort

_ft_list_sort:
	push rbp
	mov rbp, rsp
	sub rsp, 32

	cmp rdi, 0
	je .ft_ret
	cmp qword [rdi], 0
	je .ft_ret

	mov qword [rbp - 8], rdi ; save t_list **head
	mov qword [rbp - 16], rsi ; save int (*cmp)(void *, void *)

.ft_infinite_loop:
	mov rdi, qword [rdi] ; *head (deref 1st arg)
	mov rdx, qword [rdi + 8] ; temp->next
	cmp rdi, 0
	je .ft_read

.ft_loop:
	mov qword [rbp - 24], rdi
	mov word [rbp - 26], 0
	mov rsi, qword [rdx]
	cmp rax
	jg .ft_loop

	; to complete

.ft_ret:
	mov rsp, rbp
	pop rbp
	ret
