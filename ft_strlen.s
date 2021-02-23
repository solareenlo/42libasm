; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/21 13:58:32 by tayamamo          #+#    #+#              ;
;    Updated: 2021/02/21 13:58:57 by tayamamo         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

; size_t	ft_strlen(const char *s);

%ifdef MACOS
	%define FT_STRLEN	_ft_strlen
%else
	%define	FT_STRLEN	ft_strlen
%endif

			global	FT_STRLEN
			section	.text
FT_STRLEN:
			xor		rax, rax
.loop:
			cmp		byte [rdi + rax], 0
			je		.end
			inc		rax
			jmp		.loop
.end:
			ret
