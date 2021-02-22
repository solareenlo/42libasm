; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/21 16:39:12 by tayamamo          #+#    #+#              ;
;    Updated: 2021/02/21 16:39:13 by tayamamo         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%ifdef MACOS
	%define FT_STRCPY	_ft_strcpy
%else
	%define	FT_STRCPY	ft_strcpy
%endif

			global	FT_STRCPY
			section	.text
FT_STRCPY:
			push	rdi
.loop:
			mov		dl, byte [rsi]
			mov		byte [rdi], dl
			inc		rdi
			inc		rsi
			test	dl, dl
			jnz		.loop
			mov		byte [rdi], 0
			pop		rax
			ret
