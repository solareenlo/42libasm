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

; size_t	ft_strlen(const char *s);
; char		*ft_strcpy(char *dst, const char *src);
; char		*ft_strdup(const char *s1);

%ifdef MACOS
	%define FT_STRDUP	_ft_strdup
	%define FT_STRCPY	_ft_strcpy
	%define FT_STRLEN	_ft_strlen
	%define MALLOC		_malloc
	%define ERROR		___error
%else
	%define	FT_STRDUP	ft_strdup
	%define	FT_STRCPY	ft_strcpy
	%define	FT_STRLEN	ft_strlen
	%define MALLOC		malloc
	%define ERROR		__errno_location
%endif

			global	FT_STRDUP
			extern	FT_STRLEN
			extern	FT_STRCPY
			extern	MALLOC
			extern	ERROR
			section	.text
FT_STRDUP:
			call	FT_STRLEN
			inc		rax
			push	rdi
			mov		rdi, rax
%ifdef MACOS
			call	MALLOC
%else
			call	MALLOC wrt ..plt
%endif
			test	rax, rax
			jz		.error
			pop		rsi
			mov		rdi, rax
			call	FT_STRCPY
			ret
.error:
%ifndef MACOS
			neg		rax
%endif
			pop		rdi
			push	rax
%ifdef MACOS
			call	ERROR
%else
			call	ERROR wrt ..plt
%endif
			pop		qword [rax]
			mov		rax, 0
			ret
