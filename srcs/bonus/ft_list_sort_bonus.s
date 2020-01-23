section .text
	global _ft_list_sort

_ft_list_sort:
	push rbp
	mov rbp, rsp

	cmp rsi, 0
	je .ret ; if 2nd arg (cmp) is NULL then jump to .ret
	cmp rdi, 0
	je .ret ; if 1st arg (head) is NULL then jump to .ret
	mov rdi, qword [rdi]
	cmp qword rdi, 0
	je .ret ; if 1st arg points to NULL (*head == NULL) then jump to .ret

	sub rsp, 32
	mov qword [rbp - 8], rdi ; save *head (deref 1st arg)
	mov qword [rbp - 16], rsi ; save int (*cmp)(void *, void *)

.infinite_loop:
	mov rdi, qword [rbp - 8] ; restore *head from stack to rdi (tmp = *head)
	mov byte [rbp - 25], 0 ; check = 0

.loop:
	mov rsi, qword [rdi + 8] ; rsi = temp->next
	cmp rsi, 0
	je .check_check ; if rsi == NULL then jump to .check_check

	mov qword [rbp - 24], rdi ; save temp
	mov rdi, qword [rdi] ; set cmp's first arg to temp->data
	mov rsi, qword [rsi] ; set cmp's second arg to temp->next->data
	call qword [rbp - 16] ; call cmp
	mov rdi, qword [rbp - 24] ; restore tmp to rdi
	cmp rax, 0
	jle .loop_end ; if cmp() <= 0 then jump to .loop_end

	mov rdx, qword [rdi] ; swp = temp->data
	mov rsi, qword [rdi + 8] ; rsi = temp->next
	mov rcx, qword [rsi] ; rcx = temp->next->data
	mov qword [rdi], rcx ; temp->data = rcx
	mov qword [rsi], rdx ; temp->next->data = swp
	mov byte [rbp - 25], 1 ; check = 1

.loop_end:
	mov rdi, qword [rdi + 8] ; temp = temp->next
	jmp .loop

.check_check:
	cmp byte [rbp - 25], 0
	je .ret ; if check == 0 then jump to .ret
	jmp .infinite_loop ; otherwise, jump to .infinite_loop

.ret:
	mov rsp, rbp
	pop rbp
	ret
