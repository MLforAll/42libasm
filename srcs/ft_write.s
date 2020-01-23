%define WRITE_SYSCALL	0x2000004

section .text
	global _ft_write
	extern ___error

_ft_write:
	push rbp
	mov rbp, rsp
	mov rax, WRITE_SYSCALL
	syscall
	jnc .ret ; if carry flag (CF) not set, syscall worked jump to .ret
	sub rsp, 16
	mov dword [rbp - 4], eax ; save value before calling __error
	call ___error
	mov ecx, dword [rbp - 4] ; restore saved eax to ecx
	mov dword [rax], ecx ; set errno
	mov rax, -1
.ret:
	mov rsp, rbp
	pop rbp
	ret
