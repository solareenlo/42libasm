			section		.data
codes:		db	   		'0123456789ABCDEF'

			section		.txt
			global 		_start
_start:		mov	   		rax, 0x1A2B3C4D5E6F7A8B
			mov    		rdi, 1			; rdi = 1
			mov	   		rdx, 1			; rdx = 1
			mov	   		rcx, 64			; rcx = 64
.loop:		push   		rax				; save rax to stack
			sub	   		rcx, 4			; rcx = rcx - 4
			sar	   		rax, cl			; rax = rax >> cl
			and	   		rax, 0x0000000f	; rax = rax and 0xf

			lea	   		rsi, [codes + rax]	; copy address to rsi
			mov	   		rax, 1			; syscall write
			push   		rcx				; save rcx to stack
			syscall
			pop	   		rcx				; load rcx from stack
			pop	   		rax				; load rax from stack
			test   		rcx, rcx		; and, set SF, ZF, PF according to result.
			jnz	   		.loop			; jump not zero

			mov	   		rax, 60			; syscall exit
			xor	   		rdi, rdi		; rdi = 0
			syscall
