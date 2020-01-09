%define MACH_SYSCALL(x)	0x2000000 | x
%define READ_SYSCALL	3

section .text
	global _ft_read

_ft_read:
	push rbp
	mov rbp, rsp
	mov rax, MACH_SYSCALL(READ_SYSCALL)
	syscall
	mov rsp, rbp
	pop rbp
	ret
