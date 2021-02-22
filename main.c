/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:01:09 by tayamamo          #+#    #+#             */
/*   Updated: 2021/02/22 20:48:24 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include "libasm.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

void	test_ft_strlen(void);
void	check_ft_strlen(char *s);
void	test_ft_strcpy(void);
void	check_ft_strcpy(char *src);
void	test_ft_strcmp(void);
void	check_ft_strcmp(char *s1, char *s2);
void	test_ft_write(void);
char	*long_char(size_t size, char c);

int		main(void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	return (0);
}

void	test_ft_write(void)
{
	printf("%sCheck%s ft_write\n", GREEN, RESET);
	errno = 0;
	printf("%lu %d\n", write(-1, "abc ", 5), errno);
	printf("%lu %d\n", write(0, "abc ", 5), errno);
	printf("%lu %d\n", write(1, "abc ", 5), errno);
	printf("%lu %d\n", write(2, "abc ", 5), errno);
	printf("%lu %d\n", write(3, "abc ", 5), errno);
	printf("%lu %d\n", write(1, "abc ", 5), errno);
}

void	test_ft_strcmp(void)
{
	char	*s;

	printf("%sCheck%s ft_strcmp\n", GREEN, RESET);
	check_ft_strcmp("hello", "hello");
	check_ft_strcmp("hello", "hello!");
	check_ft_strcmp("hello", "hellO");
	check_ft_strcmp("hellO", "hello");
	check_ft_strcmp(" ", "  ");
	check_ft_strcmp("  ", " ");
	check_ft_strcmp("", "");
	check_ft_strcmp("\n", "\n");
	check_ft_strcmp("\0a\0", "\0a\0");
	check_ft_strcmp("aaa", "a\0a\0a");
	check_ft_strcmp("!@#$%^&*()_+|~QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?", "!@#$%^&*()_+|~QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?");
	s = long_char(100, 'C');
	check_ft_strcmp(s, "a");
	check_ft_strcmp(s, s);
	free(s);
	write(1, "\n", 1);
}

void	check_ft_strcmp(char *s1, char *s2)
{
	if (strcmp(s1, s2) == ft_strcmp(s1, s2))
		printf("%sOK%s [%s] [%s]\n", GREEN, RESET, s1, s2);
	else
	{
		printf("%sNG%s [%s] [%s]", RED, RESET, s1, s2);
		printf(" %d %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
	}
}

void	test_ft_strcpy(void)
{
	char	*s;

	printf("%sCheck%s ft_strcpy\n", GREEN, RESET);
	check_ft_strcpy("hello world");
	check_ft_strcpy("");
	check_ft_strcpy("          ");
	check_ft_strcpy(" a ");
	check_ft_strcpy("0x 0 0 \' \' \"\" ");
	check_ft_strcpy("\0\0\0");
	check_ft_strcpy("\n\n");
	check_ft_strcpy("a\0b\0c\0");
	check_ft_strcpy("!@#$%^&*()_+|~QWERTYUIOP{}ASDFGHJKL:ZXCVBNM<>?");
	check_ft_strcpy(":\"A");
	check_ft_strcpy("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	check_ft_strcpy("!@#$%^&*()_+|~\"QWERTYUIOP{}ASDFGHJKL:ZXCVBNM<>?");
	check_ft_strcpy("!@#$%^&*()_+|~\"QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?");
	check_ft_strcpy("\'\'\'\'\'\'\'\'");
	check_ft_strcpy("\"\"\"\"\"\"\"\"");
	s = long_char(100, 'A');
	check_ft_strcpy(s);
	free(s);
	write(1, "\n", 1);
}

void	check_ft_strcpy(char *src)
{
	char	*dst1;
	char	*dst2;

	if ((dst1 = malloc(strlen(src) + 1)) == NULL)
	{
		dprintf(2, "malloc failed\n");
		exit(1);
	}
	if ((dst2 = malloc(strlen(src) + 1)) == NULL)
	{
		dprintf(2, "malloc failed\n");
		exit(1);
	}
	strcpy(dst1, src);
	ft_strcpy(dst2, src);
	if (strcmp(dst1, dst2) == 0 && strcmp(src, dst1) == 0 && strcmp(src, dst2) == 0)
		printf("%sOK%s [%s]\n", GREEN, RESET, src);
	else
		printf("%sNG%s [%s]\n", RED, RESET, src);
	free(dst1);
	free(dst2);
}

void	test_ft_strlen(void)
{
	char	*s;

	printf("%sCheck%s ft_strlen\n", GREEN, RESET);
	check_ft_strlen("hello world");
	check_ft_strlen("");
	check_ft_strlen(" ");
	check_ft_strlen("0x 0 0 \' \' \"\" ");
	check_ft_strlen("\0\0\0");
	check_ft_strlen("\n\n");
	check_ft_strlen("a\0b\0c\0");
	check_ft_strlen("!@#$%^&*()_+|~QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?");
	s = long_char(101, 'B');
	check_ft_strlen(s);
	free(s);
	write(1, "\n", 1);
}

void	check_ft_strlen(char *s)
{
	if (strlen(s) == ft_strlen(s))
		printf("%sOK%s [%s]\n", GREEN, RESET, s);
	else
		printf("%sNG%s [%s]\n", RED, RESET, s);
}

char	*long_char(size_t size, char c)
{
	char	*s;

	if ((s = malloc(size)) == NULL)
	{
		dprintf(2, "malloc failed\n");
		exit(1);
	}
	s[--size] = '\0';
	while (--size)
		s[size] = c;
	return (s);
}
