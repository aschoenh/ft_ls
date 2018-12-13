/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:14:00 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/13 18:37:19 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

t_file_list		*ft_ls_list_files(char **av, int ac, int i)
{
	t_file_list	*begin_list;

	if (i > 0)
		i = 1;
	else
		i = 0;
	begin_list = NULL;
	if (ac == 1)
		ft_ls_get_file("", ".", &begin_list);
	else
		while (av[++i])
			if ((ft_ls_get_file("", av[i], &begin_list) == -1))
				ft_ls_error(ERRNO, av[1], 0);
	return (begin_list);
}

int			main(int ac, char **av)
{
	int			i;
	int			options; // l = 20000 R = 2000 a = 200 r = 20 t = 2
	t_file_list	*file;

	if (ac > 1)
	{
		if ((i = ft_ls_parsing(ac, av, &options)) == -1)
			return (EXIT_FAILURE);
	}
	else
	{
		i = 0;
		options = 0;
	}
	file = ft_ls_list_files(av, ac, i);
/*	ft_ls_display(options, file, ac);
	ft_list_clear(&file);
	return (EXIT_SUCCESS);
}*/
