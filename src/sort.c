/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:05:33 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/11 16:56:25 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_list_reverse(t_file_list **begin_list)
{
	t_file_list		*prev;
	t_file_list		*current;
	t_file_list		*next;

	next = NULL;
	prev = NULL;
	current = NULL;
	if (!begin_list || !*begin_list)
		return ;
	current = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

static void			ft_list_sort_time(t_file_list **lst)
{
XXXXXXXXXX
}

void				ft_sort_list(t_file_list **lst, int options)
{
	int optionss;
	int optionsss;

	optionss = options;
	optionsss = options;
	ft_list_sort(lst, (f*)(ft_strcmp));
		if (((optionsss / 10) + 3) % 5 == 0)
			ft_list_reverse(lst);
		if ((optionss + 3) % 5 == 0)
			ft_list_sort_time(lst);
}
