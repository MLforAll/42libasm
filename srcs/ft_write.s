%define MACH_SYSCALL(x)	0x2000000 | x
%define WRITE_SYSCALL	4

section .text
	global _ft_write

_ft_write:
	mov rax, MACH_SYSCALL(WRITE_SYSCALL)
	syscall
	ret
