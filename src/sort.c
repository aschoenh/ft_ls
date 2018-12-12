/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:05:33 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/12 17:11:16 by aschoenh         ###   ########.fr       */
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

static t_file_list	*ft_list_sort_time(t_file_list *lst)
{
	if (!lst)
		return (NULL);
	if ((lst->next && lst->time_set < lst->next->time_set))
		lst = ft_lst_swap(lst, lst->next);
	else if (lst->next && lst->time_set == lst->next->time_set)
		if (lst->next && (lst->time < lst->next->time))
			lst = ft_lst_swap(lst, lst->next);
	lst->next = ft_list_sort_time(lst->next);
	if (lst->next && (lst->time_set < lst->next->time_set))
	{
		lst = ft_lst_swap(lst, lst->next);
		lst->next = ft_list_sort_time(lst->next);
	}
	else if (lst->next && lst->time_set == lst->next->time_set)
	{
		if (lst->next && (lst->time < lst->next->time))
		{
			lst = ft_lst_swap(lst, lst->next);
			lst->next = ft_list_sort_time(lst->next);
		}
	}
	return (lst);
}

void				ft_sort_list(t_file_list **lst, int options)
{
	int				optionss;
	int				optionsss;

	optionss = options;
	optionsss = options;
//	*lst = ft_list_sort(lst, (ft_strcmp*)(lst, lst->next);
		if (((optionsss / 10) + 3) % 5 == 0)
			ft_list_reverse(lst);
		if ((optionss + 3) % 5 == 0)
			*lst = ft_list_sort_time(*lst);
}
