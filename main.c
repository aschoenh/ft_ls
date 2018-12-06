/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:14:00 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/06 16:58:09 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	int			i;
	int			options; // l = 10000 R = 1000 a = 100 r = 10 t =1
	t_tolist	*file;

	if ((i = ft_ls_parsing(ac, av, &options)) == -1)
		return (-1);
	/*
	file = ft_ls_create_list(av, ac);
	ft_ls_display(options, file_list, ac);
	ft_ls_free_list(&file_list);
	*/
	return (0);
}
