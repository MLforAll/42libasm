section .text
	global _ft_list_sort

_ft_list_sort:
	push rbp
	mov rbp, rsp
	sub rsp, 48

	cmp rdi, 0
	je .ft_ret ; if 1st arg (head) is NULL then jump to .ft_ret
	cmp qword [rdi], 0
	je .ft_ret ; if 2nd arg (cmp) is NULL then jump to .ft_ret

	mov rdi, qword [rdi]
	mov qword [rbp - 8], rdi ; save *head (deref 1st arg)
	mov qword [rbp - 16], rsi ; save int (*cmp)(void *, void *)

.ft_infinite_loop:
	mov rdi, qword [rbp - 8] ; restore head from stack to rdi (tmp = *head)
	mov qword [rbp - 32], 0 ; check = 0

.ft_loop:
	mov rsi, qword [rdi + 8] ; rsi = temp->next
	cmp rsi, 0
	je .check_check ; if rsi == NULL then jump to .check_check

	mov qword [rbp - 24], rdi ; save temp
	mov rdi, qword [rdi] ; set cmp's first arg to temp->data
	mov rsi, qword [rsi] ; set cmp's second arg to temp->next->data
	call qword [rbp - 16] ; call cmp
	mov rdi, qword [rbp - 24] ; restore tmp to rdi
	cmp rax, 0
	jle .ft_loop_end ; if cmp() <= 0 then jump to .ft_loop_end

	mov rdx, qword [rdi] ; swp = temp->data
	mov rsi, qword [rdi + 8] ; rsi = temp->next
	mov rcx, qword [rsi] ; rcx = temp->next->data
	mov qword [rdi], rcx ; temp->data = rcx
	mov qword [rsi], rdx ; temp->next->data = swp
	mov qword [rbp - 32], 1 ; check = 1

.ft_loop_end:
	mov rdi, qword [rdi + 8] ; temp = temp->next
	jmp .ft_loop

.check_check:
	cmp qword [rbp - 32], 0
	je .ft_ret ; if check == 0 then jump to .ft_ret
	jmp .ft_infinite_loop ; otherwise, jump to .ft_infinite_loop

.ft_ret:
	mov rsp, rbp
	pop rbp
	ret
