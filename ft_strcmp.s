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

; int		ft_strcmp(const char *s1, const char *s2);

%ifdef MACOS
	%define FT_STRCMP	_ft_strcmp
%else
	%define	FT_STRCMP	ft_strcmp
%endif

			global	FT_STRCMP
			section	.text
FT_STRCMP:
			mov		al, byte [rdi]
			cmp		al, byte [rsi]
			jne		.no
			inc		rdi
			inc		rsi
			test	al, al
			jnz		FT_STRCMP
			xor		rax, rax
			ret
.no:
			movzx	rax, byte [rdi]
			movzx	rcx, byte [rsi]
			sub		rax, rcx
			ret
