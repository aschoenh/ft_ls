/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:25:31 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/11 16:56:17 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			ft_list_clear(t_file_list **begin_list)
{
	t_file_list	*temp;
	t_file_list	*new_list;

	if (!*begin_list)
		return ;
	new_list = *begin_list;
	while (new_list)
	{
		temp = new_list->next;
		free(new_list);
		new_list = temp;
	}
	*begin_list = NULL;
}
/*
int				ft_list_longest_name(t_file_list **lst)
{
	int			len;

	len = 0;
	while (*lst)
	{
		len = ft_max(ft_strlen((*lst)->name, len));
		*lst = (*lst)->next;
	}
	return (len);
}
*
*//*
void			ft_lst_swap(t_file_list **file1, t_file_list *file2)
{
	(*file1)->next = (*file2)->next;
	(*file2)->next = *file1;
}*/

void			ft_list_sort(t_file_list **begin_list, int (*cmp)())
{
	t_file_list	*current;
	t_file_list	*current2;
	t_file_list	*next;

	current = NULL;
	if (!begin_list || !*begin_list)
		return ;
	current = *begin_list;
	while (current)
	{
		current2 = *begin_list;
		while (current2->next)
		{
			if ((*cmp)(current2->name, current2->next->name) > 0)
			{
				next = current2->name;
				current2->name = current2->next->name;
				current2->next->name = next;
			}
			current2 = current2->next;
		}
		current = current->next;
	}
}


int				ft_get_int_len(int n)
{
	int			rep;

	rep = 1;
	while (n / 10)
	{
		n /= 10;
		rep++;
	}
	return (rep);
}
