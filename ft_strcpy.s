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

			global	_ft_strcpy
			section	.text
_ft_strcpy:
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
