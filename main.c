/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:01:09 by tayamamo          #+#    #+#             */
/*   Updated: 2021/02/21 16:29:57 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "libasm.h"

void	check_ft_strlen(void);
void	assert_ft_strlen(char *s);

int		main(void)
{
	check_ft_strlen();
	return (0);
}

void	check_ft_strlen(void)
{
	char	*s;

	printf("Check ft_strlen\n");
	assert_ft_strlen("hello world");
	assert_ft_strlen("");
	assert_ft_strlen(" ");
	assert_ft_strlen("0x 0 0 \' \' \"\" ");
	if ((s = calloc(101, 1)) == NULL)
	{
		dprintf(2, "malloc failed\n");
		exit(1);
	}
	for (int i = 0; i < 100; i++)
		s[i] = 'A';
	assert_ft_strlen(s);
	free(s);
}

void	assert_ft_strlen(char *s)
{
	assert(ft_strlen(s) == strlen(s));
	printf("\033[32mOK\033[0m [%s]\n", s);
}
