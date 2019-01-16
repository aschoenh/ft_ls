/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:14:00 by aschoenh          #+#    #+#             */
/*   Updated: 2019/01/16 16:35:45 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

t_file_list		*ft_ls_list_files(char **av, int ac, int *i, int isfirst)
{
	t_file_list	*begin_list;
	int			k;

	k = *i + 1;
	begin_list = NULL;
	if (ac == k)
		ft_ls_get_file("", ".", &begin_list);
	else
		sort_args(av, ac, k, i);
	while (av[k])
	{
		if (av[k][0] == '\0')
		{
			ft_ls_error(0, "fts_open", 0);
			return (NULL);
		}
			//ft_printf("|%s|\n", av[k]);
		if ((ft_ls_get_file("", av[k], &begin_list) == -1) && isfirst)
		{
			ft_ls_error(ERRNO, av[k], 0);
			(*i)--;
		}
//	ft_printf("  i %d    ", *i);
		k++;
	}
	return (begin_list);
}

int			main(int ac, char **av)
{
	int			i;
	int			options;
	int			isfile;
	int			count;
//	int			isfirst;
	t_file_list	*file;

	if ((i = ft_ls_parsing(ac, av, &options)) == -1)
		return (EXIT_FAILURE);
	count = i;
	file = ft_ls_list_files(av, ac, &count, 1);
	if (count > 1)
		ft_ls_display_files(&file, options, count - i - 1);
	isfile = (!file ? 1 : 0);
	ft_ls_display(options, file, ac - i - 1, !isfile ? 2 : 1 );
	ft_list_clear(&file);
	return (EXIT_SUCCESS);
}
