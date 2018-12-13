/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:37:13 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/13 17:15:57 by mporzier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>
#include <string.h>

int		ft_ls_parsing(int ac, char **av, int *options)
{
	int			ret;
	int			i;
	int			k;

	ret = 9000000;
	*options = 0;
	i = 1;
	k = 1;
	while (k < ac && av[k][0] == '-' && av[k][1] != '\0')
	{
		while (av[k][i])
		{
			ret += ft_ls_parse_options(av[k][i], options);
			if (ret % 2 != 0)
				return (ft_ls_error(USAGE, av[1], i));
			i++;
		}
		i = 1;
		k++;
	}
	return (k - 1);
}

int		ft_ls_parse_options(char flag, int *options)
{
	if (flag == 's' || flag == 'l' || flag == 'R' || flag == 'a'
			|| flag == 'r' || flag == 't')
	{
		if (flag == 's' && (((*options / 100000) + 3) % 5) != 0)
			*options += 200000;
		if (flag == 'l' && (((*options / 10000) + 3) % 5) != 0)
			*options += 20000;
		if (flag == 'R' && (((*options / 1000) + 3) % 5) != 0)
			*options += 2000;
		if (flag == 'a' && (((*options / 100) + 3) % 5) != 0)
			*options += 200;
		if (flag == 'r' && (((*options / 10) + 3) % 5) != 0)
			*options += 20;
		if (flag == 't' && (((*options / 1) + 3) % 5) != 0)
			*options += 2;
	}
	else
		return (-1);
	return (0);
}


int		ft_ls_error(int error, char *str, int index)
{
	if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(str[index], 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-alRrst] [file ...]", 2);
	}
	if (error == ERRNO)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(ERRNO), 2);
	}
	if (error == USAGE || error == MALL_ERR)
		exit(EXIT_FAILURE);
	return (0);

}
