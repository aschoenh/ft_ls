/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:53:10 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/14 17:16:14 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void static		ft_swap(char **s1, char **s2)
{
	void	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int				sort_args(char **av, int ac, int i)
{
	int j;

	j = 1;
	while (i < ac - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			ft_swap(&av[i], &av[i + 1]);
			i = 1;
		}
		else
			i++;
	}
	i = 1;
	return (0);
}
