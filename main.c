/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:01:09 by tayamamo          #+#    #+#             */
/*   Updated: 2021/02/21 21:53:12 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "libasm.h"

void	test_ft_strlen(void);
void	check_ft_strlen(char *s);
void	test_ft_strcpy(void);
void	check_ft_strcpy(char *src);

int		main(void)
{
	test_ft_strlen();
	write(1, "\n", 1);
	test_ft_strcpy();
	write(1, "\n", 1);
	return (0);
}

void	test_ft_strcpy(void)
{
	printf("Check ft_strcpy\n");
	check_ft_strcpy("hello world");
	check_ft_strcpy("");
	check_ft_strcpy("          ");
	check_ft_strcpy(" a ");
	check_ft_strcpy("0x 0 0 \' \' \"\" ");
}

void	check_ft_strcpy(char *src)
{
	char	*dst1;
	char	*dst2;

	dst1 = malloc(strlen(src) + 1);
	dst2 = malloc(strlen(src) + 1);
	ft_strcpy(dst1, src);
	strcpy(dst2, src);
	if (strcmp(dst1, dst2) == 0)
		printf("\033[32mOK\033[0m [%s]\n", src);
	else
		printf("\033[31mNG\033[0m [%s]\n", src);
	free(dst1);
	free(dst2);
}

void	test_ft_strlen(void)
{
	char	*s;

	printf("Check ft_strlen\n");
	check_ft_strlen("hello world");
	check_ft_strlen("");
	check_ft_strlen(" ");
	check_ft_strlen("0x 0 0 \' \' \"\" ");
	if ((s = calloc(101, 1)) == NULL)
	{
		dprintf(2, "malloc failed\n");
		exit(1);
	}
	for (int i = 0; i < 100; i++)
		s[i] = 'A';
	check_ft_strlen(s);
	free(s);
}

void	check_ft_strlen(char *s)
{
	if (strlen(s) == ft_strlen(s))
		printf("\033[32mOK\033[0m [%s]\n", s);
	else
		printf("\033[31mNG\033[0m [%s]\n", s);
}
