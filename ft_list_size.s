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

%ifdef MACOS
	%define FT_LIST_SIZE	_ft_list_size
%else
	%define	FT_LIST_SIZE	ft_list_size
%endif

			global	FT_LIST_SIZE
			section	.text
FT_LIST_SIZE:
			xor		rax, rax
.loop:
			cmp		rdi, 0
			je		.end
			mov		rdi, [rdi + 8]
			inc		rax
			jmp		.loop
.end:
			ret
