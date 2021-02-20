section .text

exit:
	xor		rdi, rdi
	mov		rax, 60
	syscall

string_length:
	xor		rax, rax
.loop:
	cmp		byte [rdi+rax], 0
	je		.end
	inc		rax
	jmp		.loop
.end:
	ret

print_string:
	push	rdi
	call	string_length
	pop		rsi
	mov		rdx, rax
	mov		rax, 1
	mov		rdi, 1
	syscall
	ret


print_char:
	push	rdi
	mov		rdi, rsp
	call	print_string
	pop		rdi
	ret

print_newline:
	mov		rdi, 0xA
	jmp		print_char


print_uint:
	mov		rax, rdi
	mov		rdi, rsp
	push	0
	sub		rsp, 16
	dec		rdi
	mov		r8, 10
.loop:
	xor		rdx, rdx
	div		r8
	or		dl, 0x30
	dec		rdi
	mov		[rdi], dl
	test	rax, rax
	jnz		.loop

	call	print_string
	add		rsp, 24
	ret


print_int:
	test	rdi, rdi
	jns		print_uint
	push	rdi
	mov		rdi, '-'
	call	print_char
	pop		rdi
	neg		rdi
	jmp		print_uint
	ret

string_equals:
    xor rax, rax
    ret


read_char:
	push	0
	xor		rax, rax
	xor		rdi, rdi
	mov		rsi, rsp
	mov		rdx, 1
	syscall
	pop		rax
	ret

read_word:
	push	r14
	push	r15
	xor		r14, r14
	mov		r15, rsi
	dec		r15
.A:
	push	rdi
	call	read_char
	pop		rdi
	cmp		al, ' '
	je		.A
	cmp		al, 9
	je		.A
	cmp		al, 10
	je		.A
	cmp		al, 11
	je		.A
	cmp		al, 12
	je		.A
	cmp		al, 13
	je		.A
	test	al, al
	jz		.C
.B:
	mov		byte [rdi + r14], al
	inc		r14
	push	rdi
	call	read_char
	pop		rdi
	cmp		al, ' '
	je		.C
	cmp		al, 9
	je		.C
	cmp		al, 10
	je		.C
	cmp		al, 11
	je		.C
	cmp		al, 12
	je		.C
	cmp		al, 13
	je		.C
	test	al, al
	jz		.C
	cmp		r14, r15
	je		.D
    jmp		.B
.C:
    mov		byte [rdi + r14], 0
    mov		rax, rdi
    mov		rdx, r14
    pop		r15
    pop		r14
    ret
.D:
    xor		rax, rax
    pop		r15
    pop		r14
	ret


; rdi points to a string
; returns rax: number, rdx : length
parse_uint:
    xor rax, rax
    ret

; rdi points to a string
; returns rax: number, rdx : length
parse_int:
    xor rax, rax
    ret


string_copy:
	push	rdi
	push	rsi
	push	rdx
	call	string_length
	pop		rdx
	pop		rsi
	pop		rdi

	cmp		rax, rdx
	jae		.too_long

	push	rsi

.loop:
	mov		dl, byte[rdi]
	mov		byte[rsi], dl
	inc		rdi
	inc		rsi
	test	dl, dl
	jnz		.loop

	pop		rax
	ret

.too_long:
	xor		rax, rax
	ret
