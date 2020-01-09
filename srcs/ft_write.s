%define MACH_SYSCALL(x)	0x2000000 | x
%define WRITE_SYSCALL	4

section .text
	global _ft_write

_ft_write:
	push rbp
	mov rbp, rsp
	mov rax, MACH_SYSCALL(WRITE_SYSCALL)
	syscall
	mov rsp, rbp
	pop rbp
	ret
