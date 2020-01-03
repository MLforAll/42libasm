%define MACH_SYSCALL(x)	0x2000000 | x
%define READ_SYSCALL	3
%define WRITE_SYSCALL	4

section .data
	hello_world     db      "Hello World!", 0x0a

section .bss
	buff: resb 512

section .text
	global _main
	global _ft_read
	global _ft_write

_ft_read:
	mov rax, MACH_SYSCALL(READ_SYSCALL)
	syscall
	ret

_ft_write:
	mov rax, MACH_SYSCALL(WRITE_SYSCALL)
	syscall
	ret

_main:
	mov rdi, 1
	mov rsi, hello_world
	mov rdx, 14
	call _ft_write
	mov rdi, 0
	mov rsi, buff
	mov rdx, 512
	call _ft_read
	mov rax, 0x2000001      ; System call number for exit = 1
	mov rdi, 0              ; Exit success = 0
	syscall                 ; Invoke the kernel
