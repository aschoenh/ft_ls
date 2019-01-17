/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:05:33 by aschoenh          #+#    #+#             */
/*   Updated: 2019/01/17 17:45:40 by aschoenh         ###   ########.fr       */
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

t_file_list			*ft_list_sort_block(t_file_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && lst->st_blocks > lst->next->st_blocks)
		lst = ft_lst_swap(lst, lst->next);
	else if (lst->next && lst->st_blocks == lst->next->st_blocks)
		if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
			lst = ft_lst_swap(lst, lst->next);
	lst->next = ft_list_sort_block(lst->next);
	if (lst->next && lst->st_blocks > lst->next->st_blocks)
	{
		lst = ft_lst_swap(lst, lst->next);
		lst->next = ft_list_sort_block(lst->next);
	}
	else if (lst->next && lst->st_blocks == lst->next->st_blocks)
	{
		if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		{
			lst = ft_lst_swap(lst, lst->next);
			lst->next = ft_list_sort_block(lst->next);
		}
	}
	return (lst);
}

static t_file_list	*ft_list_sort_ascii(t_file_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = ft_lst_swap(lst, lst->next);
	lst->next = ft_list_sort_ascii(lst->next);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = ft_lst_swap(lst, lst->next);
		lst->next = ft_list_sort_ascii(lst->next);
	}
	return (lst);
}

void				ft_sort_list(t_file_list **lst, int options, int count)
{
	int				optionss;
	int				optionsss;
	t_file_list		*lst1;
	t_file_list		*lst2;
	int				i;

	i = 0;
	lst1 = NULL;
	if (count > 0)
	{
	lst1 = *lst;
	lst2 = lst1;
		while (lst1 && i < count && count > 0)
		{
			if (i < count)
				lst1 = lst1->next;
			i++;
		}
		while (lst2 && --i && count > 0)
			lst2 = lst2->next;
		lst2->next = NULL;
	}
	optionss = options;
	optionsss = options;
	if (count < 1)
		*lst = ft_list_sort_ascii(*lst);
	if ((optionss + 3) % 5 == 0)
	{
		*lst = ft_list_sort_time(*lst);
		if (lst1)
			lst1 = ft_list_sort_time(lst1);
	}
	if (((optionsss / 10) + 3) % 5 == 0)
	{
		ft_list_reverse(lst);
		if (lst1)
			ft_list_reverse(&lst1);
	}
	if (lst1 && count > 0)
	{
		if (lst2->next)
			lst2->next->next = lst1;
		else
			lst2->next = lst1;
	}
}
