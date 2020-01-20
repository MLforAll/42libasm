section .data
charset_lc:
	.string db "0123456789abcdef"
	.len equ $ - charset_lc.string
charset_up:
	.string db "0123456789ABCDEF"
	.len equ $ - charset_up.string

section .text
	global _ft_atoi_base

; _atoi_isdigit and _char_to_int don't comply to calling conventions
; they don't init a new stack frame (push rbp, change rbp, etc...)
; they are only meant to be used by this ASM version of _ft_atoi_base

_atoi_isdigit:
	lea rdx, [rel charset_lc.string]
.idlc_loop:
	cmp byte [rdx], 0
	je .idup
	mov r8b, byte [rdx]
	cmp r8b, byte [rdi]
	je .idret
	inc rdx
	jmp .idlc_loop
.idup:
	lea rdx, [rel charset_up.string]
.idup_loop:
	cmp byte [rdx], 0
	je .idnret
	mov r8b, byte [rdx]
	cmp r8b, byte [rdi]
	je .idret
	inc rdx
	jmp .idup_loop
.idnret:
	mov dl, 0
	ret
.idret:
	mov dl, 1
	ret

_char_to_int:
	cmp byte [rdi], '0'
	jl .lc
	cmp byte [rdi], '9'
	jg .lc
	movsx edx, byte [rdi]
	sub edx, '0'
	ret
.lc:
	movsx edx, byte [rdi]
	cmp byte [rdi], 'a'
	jl .up
	cmp byte [rdi], 'z'
	jg .up
	sub edx, 'a'
	add edx, 10
	ret
.up:
	sub edx, 'A'
	add edx, 10
	ret

_ft_atoi_base:
	push rbp
	mov rbp, rsp

	mov eax, 0

	cmp esi, 2 ; if (base < 2) return
	jl .ft_ret
	cmp esi, 16 ; if (base > 16) return
	jg .ft_ret

.ws_loop:
	cmp byte [rdi], 0
	je .ft_ret
	cmp byte [rdi], '+'
	je .ws_loop_end
	cmp byte [rdi], '-'
	je .ws_loop_end
	cmp byte [rdi], ' '
	jne .ws_loop_end
	cmp byte [rdi], 9
	jne .ws_loop_end
	cmp byte [rdi], 10
	jne .ws_loop_end
	cmp byte [rdi], 11
	jne .ws_loop_end
	cmp byte [rdi], 12
	jne .ws_loop_end
	cmp byte [rdi], 13
	jne .ws_loop_end
	inc rdi
	jmp .ws_loop

.ws_loop_end:
	mov cx, 0 ; flag for negative
	cmp byte [rdi], '-'
	jne .notneg
	mov cx, 1
.notneg:
	call _atoi_isdigit
	cmp dl, 0 ; retval of inline _atoi_isdigit
	jne .main_loop

	cmp byte [rdi], '+'
	je .main_loop
	cmp cx, 0
	jne .main_loop
	inc rdi

.main_loop:
	cmp byte [rdi], 0
	je .finish
	call _atoi_isdigit
	cmp dl, 1 ; retval of inline _atoi_isdigit
	jne .finish
	call _char_to_int
	imul eax, esi ; ret *= base
	add eax, edx
	inc rdi
	jmp .main_loop

.finish:
	cmp cx, 1
	jne .ft_ret
	neg eax
.ft_ret:
	mov rsp, rbp
	pop rbp
	ret
