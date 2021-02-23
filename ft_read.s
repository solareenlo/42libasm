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

; ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

%ifdef MACOS
	%define FT_READ		_ft_read
	%define ERROR		___error
	%define READ		0x02000003
%else
	%define	FT_READ		ft_read
	%define ERROR		__errno_location
	%define READ		0
%endif

			global	FT_READ
			section	.text
			extern	ERROR
FT_READ:
			mov		rax, READ
			syscall
%ifdef MACOS
			jc		.error
%else
			cmp		rax, 0
			jl		.error
%endif
			ret
.error:
%ifndef MACOS
			neg		rax
%endif
			push	rax
%ifdef MACOS
			call	ERROR
%else
			call	ERROR wrt ..plt
%endif
			pop		qword [rax]
			mov		rax, -1
			ret
