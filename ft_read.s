; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/22 01:48:28 by tayamamo          #+#    #+#              ;
;    Updated: 2021/02/22 01:48:28 by tayamamo         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

			global	_ft_read
			section	.text
			extern	___error
_ft_read:
			mov		rax, 0x02000003
			syscall
			jc		.error
			ret
.error:
			push	rax
			call	___error
			pop		qword [rax]
			mov		rax, -1
			ret
