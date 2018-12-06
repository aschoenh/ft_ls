/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:37:13 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/06 18:43:14 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

int		ft_ls_parsing(int ac, char **av, int *options)
{
	int			ret;

	ret = 0;
	*options = 0;
	if (*av[1] == '-' && *(av[1]++))
		ret = ft_ls_parse_options(av[1], options);
	return (ret);
}

int		ft_ls_parse_options(char *flags, int *options)
{
	char		*str;

	if (ft_strchr(flags, 'l'))
		options += 10000;
	if (ft_strchr(flags, 'R'))
		options += 1000;
	if (ft_strchr(flags, 'a'))
		options += 100;
	if (ft_strchr(flags, 'r'))
		options += 10;
	if (ft_strchr(flags, 't'))
		options += 1;
	return (*options);
}

/*
int		ft_ls_error(int error, char *s)
{

}*/
