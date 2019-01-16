/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:20:28 by aschoenh          #+#    #+#             */
/*   Updated: 2019/01/16 13:31:45 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list_merge(t_file_list **begin_list1, t_file_list *begin_list2)
{
	t_file_list *current;

	if (!begin_list1 || !begin_list2)
		return ;
	else if ((*begin_list1) == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	current = *begin_list1;
	while (current->next)
		current = current->next;
	current->next = begin_list2;
}
