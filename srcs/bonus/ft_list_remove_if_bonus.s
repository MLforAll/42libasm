section .text
	global _ft_list_remove_if
	extern _free
	extern _raise

; In the comments:
;	-> head is a (t_list **)
;	-> data is a argument (void *) for the cb func
;	-> cmp is the callback func taking two (void *) arguments

_ft_list_remove_if:
	push rbp
	mov rbp, rsp

	cmp rdi, 0 ; check that head is non-null
	je .ret
	mov rcx, qword [rdi] ; rcx = *head
	cmp rcx, 0
	je .ret
	cmp rdx, 0 ; check that cmp is non-null
	je .ret

	sub rsp, 48
	mov qword [rbp - 8], rdi ; save head
	mov qword [rbp - 16], rsi ; save data
	mov qword [rbp - 24], rdx ; save cmp
	mov qword [rbp - 32], rcx ; t_list *curr = rcx
	mov qword [rbp - 40], rcx ; t_list *prev = rcx

	; test initial
	mov rdi, rsi ; 1st arg = data
	mov rsi, qword [rcx] ; 2nd arg = (*head)->data
	call rdx ; call cmp
	cmp rax, 0
	jne .loop_start ; cmp() != 0 -> jump to .loop_start
	mov rdi, qword [rbp - 8] ; restore head from stack to rdi
	mov rsi, qword [rdi] ; rsi = *head
	mov rdx, qword [rsi + 8] ; rdx = rsi->next;
	mov qword [rdi], rdx
	mov rdi, rsi
	call _free
	jmp .ret

.loop_start:
	mov rdi, qword [rbp - 32] ; restore curr from stack to rdi
.loop:
	cmp rdi, 0
	je .ret ; cmp == NULL -> jump to .ret

	mov rdi, qword [rdi] ; rdi = rdi->data
	mov rsi, qword [rbp - 16] ; restore data from stack to rsi
	call qword [rbp - 24] ; call cmp
	mov rdi, qword [rbp - 32] ; rdi = curr
	cmp rax, 0
	je .loop_end ; cmp() == 0 -> jump to .loop_end

	mov qword [rbp - 40], rdi ; prev = rdi
	mov rdi, qword [rdi + 8] ; rdi = curr->next
	mov qword [rbp - 32], rdi ; curr = rdi
	jmp .loop

.loop_end:
	mov rdx, qword [rbp - 40] ; rdx = prev
	mov rcx, qword [rdi + 8] ; rcx = rdi->next (curr->next)
	mov qword [rdx + 8], rcx; rdx->next = rcx (prev->next = curr->next)
	call _free ; free(rdi) => free curr

.ret:
	mov rsp, rbp
	pop rbp
	ret
