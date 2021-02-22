; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/22 00:35:58 by tayamamo          #+#    #+#              ;
;    Updated: 2021/02/22 00:35:58 by tayamamo         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

			global	_ft_write
			section	.text
			extern	___error
_ft_write:
			mov		rax, 0x02000004
			syscall
			jc		.error
			ret
.error:
			push	rax
			call	___error
			pop		qword [rax]
			mov		rax, -1
			ret
