/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 06:48:25 by tayamamo          #+#    #+#             */
/*   Updated: 2021/02/23 13:06:00 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libasm_bonus.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

void
	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->data);
	free(lst);
}

void
	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
	return ;
}

int
	lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

void
	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
	return ;
}

t_list
	*ft_lstnew(void *data)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void
	check_ft_list_size(t_list *lst)
{
	if (ft_list_size(lst) == lstsize(lst))
		printf("%sOK%s [%d]\n", GREEN, RESET, ft_list_size(lst));
	else
		printf("%sNG%s [%d]\n", RED, RESET, ft_list_size(lst));
}

int
	main(void)
{
	t_list	*head;

	head = NULL;
	check_ft_list_size(head);
	ft_lstadd_front(&head, ft_lstnew(strdup("hello")));
	check_ft_list_size(head);
	ft_lstadd_front(&head, ft_lstnew(strdup("world")));
	check_ft_list_size(head);
	ft_lstadd_front(&head, ft_lstnew(strdup("A")));
	check_ft_list_size(head);
	ft_lstadd_front(&head, ft_lstnew(strdup("B")));
	check_ft_list_size(head);
	ft_lstclear(&head, free);
	check_ft_list_size(head);
	ft_lstadd_front(&head, ft_lstnew(strdup("")));
	check_ft_list_size(head);
	ft_lstadd_front(&head, ft_lstnew(strdup("1")));
	check_ft_list_size(head);
	ft_lstclear(&head, free);
	check_ft_list_size(head);
	return (0);
}
