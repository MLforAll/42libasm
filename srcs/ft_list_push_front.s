section .text
	global _ft_list_push_front

; In the comments:
;	-> head is a (t_list **) and is the first arg
;	-> e is the element (t_list *) we wish to add

_ft_list_push_front:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je .ret
	cmp rsi, 0
	je .ret
	mov rdx, qword [rdi] ; eq to: t_list *tmp = *head
	mov qword [rsi + 8], rdx ; eq to: e->next = tmp
	mov qword [rdi], rsi ; eq to: *head = e
.ret:
	mov rsp, rbp
	pop rbp
	ret
