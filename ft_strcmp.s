; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/21 22:05:32 by tayamamo          #+#    #+#              ;
;    Updated: 2021/02/21 22:05:32 by tayamamo         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

			global	_ft_strcmp
			section	.text
_ft_strcmp:
			mov		al, byte[rdi]
			cmp		al, byte[rsi]
			; jne		.no
			jg		.g
			jl		.l
			inc		rdi
			inc		rsi
			test	al, al
			jnz		_ft_strcmp
			xor		rax, rax
			ret
.no:
			sub		rax, rbx
			ret
.l:
			mov		rax, -1
			ret
.g:
			mov		rax, 1
			ret