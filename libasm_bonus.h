/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 06:38:28 by tayamamo          #+#    #+#             */
/*   Updated: 2021/02/23 06:49:52 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBASM_BONUS_H
# define LIBASM_BONUS_H

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

int				ft_list_size(t_list *begin_list);

#endif
