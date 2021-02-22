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

%ifdef MACOS
	%define FT_WRITE	_ft_write
	%define WRITE		0x02000004
	%define ERROR		___error
%else
	%define	FT_WRITE	ft_write
	%define WRITE		1
	%define ERROR		__errno_location
%endif

			global	FT_WRITE
			section	.text
			extern	ERROR
FT_WRITE:
			mov		rax, WRITE
			syscall
			jc		.error
			ret
.error:
			push	rax
			call	ERROR
			pop		qword [rax]
			mov		rax, -1
			ret
