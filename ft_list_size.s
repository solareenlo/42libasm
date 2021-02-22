; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_size.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/02/22 16:02:52 by tayamamo          #+#    #+#              ;
;    Updated: 2021/02/22 16:02:52 by tayamamo         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

; int ft_list_size(t_list *begin_list);

			global	_ft_list_size
			section	.text
_ft_list_size:
			xor		rax, rax
.loop:
			cmp		rdi, 0
			je		.end
			mov		rdi, [rdi + 8]
			inc		rax
			jmp		.loop
.end
			ret
