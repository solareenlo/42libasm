; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/22 01:49:04 by tayamamo          #+#    #+#              ;
;    Updated: 2021/02/22 01:49:04 by tayamamo         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

			global	_ft_strdup
			extern	_ft_strlen
			extern	_ft_strcpy
			extern	_malloc
			extern	___error
			section	.text
_ft_strdup:
			call	_ft_strlen
			inc		rax
			push	rdi
			mov		rdi, rax
			call	_malloc
			test	rax, rax
			jz		.error
			pop		rsi
			mov		rdi, rax
			call	_ft_strcpy
			ret
.error:
			pop		rdi
			ret
