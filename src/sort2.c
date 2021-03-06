/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:53:10 by aschoenh          #+#    #+#             */
/*   Updated: 2019/01/28 14:07:36 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void		ft_swap(char **s1, char **s2)
{
	void		*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

static int		sort_types(char **av, int ac, int beg)
{
	int			i;
	int			k;
	struct stat st[ac];

	i = beg - 1;
	while (++i < ac)
		stat(av[i], &st[i]);
	i = beg;
	while (!(S_ISDIR(st[i].st_mode)))
		i++;
	k = i;
	while (++i < ac)
		if (!(S_ISDIR(st[i].st_mode)) && i != k)
			ft_swap(&av[i], &av[k++]);
	i = beg;
	while (i < ac)
	{
		stat(av[i], &st[i]);
		if (!(S_ISDIR(st[i].st_mode)))
			i++;
		else
			break ;
	}
	return (i);
}

int				sort_args(char **av, int ac, int i, int *count)
{
	*count = sort_types(av, ac, i);
	while (i < *count - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			ft_swap(&av[i], &av[i + 1]);
			i = 1;
		}
		else
			i++;
	}
	i = *count;
	while (i + 1 < ac)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			ft_swap(&av[i], &av[i + 1]);
			i = *count;
		}
		else
			i++;
	}
	return (*count);
}
