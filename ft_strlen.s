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

			global	_ft_strlen
			section	.text
_ft_strlen:
			xor		rax, rax
.loop:
			cmp		byte [rdi + rax], 0
			je		.end
			inc		rax
			jmp		.loop
.end:
			ret
