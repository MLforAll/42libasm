section .data
charset_lc	db	"0123456789abcdef"
charset_up	db	"0123456789ABCDEF"

section .text
	global _ft_atoi_base

_ft_atoi_base:
	push rbp
	mov rbp, rsp

	mov eax, 0

	cmp rdi, 0 ; if 1st arg is NULL return
	je .ret
	cmp esi, 2 ; if (base < 2) return
	jl .ret
	cmp esi, 16 ; if (base > 16) return
	jg .ret

	mov cx, 0 ; flag for negative

.ws_loop:
	mov dl, byte [rdi]
	cmp dl, 0
	je .ret
	cmp dl, '+'
	je .ws_loop_end_positive
	cmp dl, '-'
	je .ws_loop_end_negative
	cmp dl, ' '
	je .ws_loop_inc
	cmp dl, 9
	je .ws_loop_inc
	cmp dl, 10
	je .ws_loop_inc
	cmp dl, 11
	je .ws_loop_inc
	cmp dl, 12
	je .ws_loop_inc
	cmp dl, 13
	je .ws_loop_inc
	jmp .main_loop
.ws_loop_inc:
	inc rdi
	jmp .ws_loop

.ws_loop_end_negative:
	mov cx, 1 ; flag for negative
.ws_loop_end_positive:
	inc rdi

.main_loop:
	cmp byte [rdi], 0
	je .finish
	call .isdigit
	cmp dl, 0 ; retval of inline _ft_atoi_isdigit
	je .finish ; if not digit (any char of hex charset) then jump to .finish
	call .char_to_int
	imul eax, esi ; edx = ret = base
	add eax, edx
	inc rdi
	jmp .main_loop

.finish:
	cmp cx, 1
	jne .ret
	neg eax
.ret:
	mov rsp, rbp
	pop rbp
	ret

; .isdigit and .char_to_int are utility functions that
; don't comply to calling conventions.
; they don't init a new call frame (push rbp, change rbp, etc...)
; they are only meant to be used by this ASM version of _ft_atoi_base.

.isdigit:
	lea rdx, [rel charset_lc]
	mov r10d, esi
.idlc_loop:
	cmp byte [rdx], 0
	je .idup
	cmp r10d, 0
	je .idup
	dec r10d
	mov r9b, byte [rdx]
	cmp r9b, byte [rdi]
	je .idret
	inc rdx
	jmp .idlc_loop
.idup:
	lea rdx, [rel charset_up]
	mov r10d, esi
.idup_loop:
	cmp byte [rdx], 0
	je .idnret
	cmp r10d, 0
	je .idnret
	dec r10d
	mov r9b, byte [rdx]
	cmp r9b, byte [rdi]
	je .idret
	inc rdx
	jmp .idup_loop
.idnret:
	mov dl, 0
	ret
.idret:
	mov dl, 1
	ret

.char_to_int:
	cmp byte [rdi], '0'
	jl .ctilc
	cmp byte [rdi], '9'
	jg .ctilc
	movsx edx, byte [rdi]
	sub edx, '0'
	ret
.ctilc:
	movsx edx, byte [rdi]
	cmp byte [rdi], 'a'
	jl .ctiup
	cmp byte [rdi], 'z'
	jg .ctiup
	sub edx, 'a'
	add edx, 10
	ret
.ctiup:
	sub edx, 'A'
	add edx, 10
	ret
