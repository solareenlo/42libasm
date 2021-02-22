/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:01:09 by tayamamo          #+#    #+#             */
/*   Updated: 2021/02/23 05:10:48 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include "libasm.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

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

void	check_ft_strdup(char *s)
{
	char	*dup[2];
	int		errnum[2];

	errno = 0;
	dup[0] = strdup(s);
	errnum[0] = errno;
	errno = 0;
	dup[1] = ft_strdup(s);
	errnum[1] = errno;
	if (strcmp(dup[0], dup[1]) == 0 && errnum[0] == errnum[1]
			&& strcmp(dup[0], s) == 0)
		printf("%sOK%s [%s] [%d]\n", GREEN, RESET, s, errnum[0]);
	else
		printf("%sNG%s [%s] [%d]\n", RED, RESET, s, errnum[0]);
	free(dup[0]);
	free(dup[1]);
}

void	test_ft_strdup(void)
{
	printf("%sCheck%s ft_strdup\n", GREEN, RESET);
	check_ft_strdup("hello world");
	check_ft_strdup("");
	check_ft_strdup("     ");
	check_ft_strdup("\0\0\0");
	check_ft_strdup("\0a\0");
	check_ft_strdup("a\0a\0");
}

void	check_ft_read(char *filename, size_t n)
{
	char	buf[2][1024];
	int		fd;
	int		errnum[2];
	ssize_t	ret[2];

	bzero(buf, sizeof(buf));
	fd = open(filename, O_RDONLY);
	errno = 0;
	ret[1] = ft_read(fd, buf[1], n);
	errnum[1] = errno;
	close(fd);
	fd = open(filename, O_RDONLY);
	errno = 0;
	ret[0] = read(fd, buf[0], n);
	errnum[0] = errno;
	close(fd);
	if (ret[0] == ret[1] && errnum[0] == errnum[1] && strcmp(buf[0], buf[1]) == 0)
		printf("%sOK%s [%s] [%s] [%lu] [%lu] [%d]\n",
				GREEN, RESET, filename, buf[0], n, ret[0], errnum[0]);
	else
		printf("%sNG%s [%s] [%s] [%lu] [%lu] [%d]\n",
				RED, RESET, filename, buf[0], n, ret[0], errnum[1]);
}

void	test_ft_read(void)
{
	printf("%sCheck%s ft_read\n", GREEN, RESET);
	check_ft_read("a.txt", 10);
	check_ft_read("b.txt", 10);
	check_ft_read(NULL, 10);
	check_ft_read("", 10);
	check_ft_read("a.txt", 0);
	check_ft_read("b.txt", 0);
	check_ft_read(NULL, 0);
	check_ft_read("", 0);
	check_ft_read("a.txt", -1);
	check_ft_read("b.txt", -1);
	check_ft_read(NULL, -1);
	check_ft_read("", -1);
	check_ft_read("a.txt", 1024);
	check_ft_read("b.txt", 1024);
	check_ft_read(NULL, 1024);
	check_ft_read("", 1024);
}

void	check_ft_write(int fd, const void *buf, size_t n)
{
	errno = 0;
	printf("[%lu] ", write(fd, buf, n));
	printf("[%d]\n", errno);
	errno = 0;
	printf("[%lu] ", ft_write(fd, buf, n));
	printf("[%d]\n", errno);
}

void	test_ft_write(void)
{
	char	*s;

	printf("%sCheck%s ft_write\n", GREEN, RESET);
	check_ft_write(-1, "[abc] ", 7);
	check_ft_write(0, "[abc] ", 7);
	check_ft_write(1, "[abc] ", 0);
	check_ft_write(1, "[abc] ", -1);
	check_ft_write(1, NULL, 1);
	check_ft_write(1, NULL, -1);
	check_ft_write(-1, NULL, -1);
	check_ft_write(1, "[abc] ", 7);
	check_ft_write(1, "[\0a\0] ", 7);
	check_ft_write(1, "[\0\0\0] ", 7);
	check_ft_write(1, "[] ", 4);
	check_ft_write(1, "[\t] ", 5);
	check_ft_write(1, "[\n] ", 5);
	check_ft_write(1, "[   ] ", 7);
	check_ft_write(2, "[abc] ", 7);
	check_ft_write(3, "[abc] ", 7);
	check_ft_write(INT_MAX, "[abc] ", 7);
	check_ft_write(INT_MIN, "[abc] ", 7);
	check_ft_write(1, s = long_char(100, 'A'), 100);
	free(s);
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

void	check_ft_strlen(char *s)
{
	if (strlen(s) == ft_strlen(s))
		printf("%sOK%s [%s]\n", GREEN, RESET, s);
	else
		printf("%sNG%s [%s]\n", RED, RESET, s);
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

int		main(void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	return (0);
}
