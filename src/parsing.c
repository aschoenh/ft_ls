/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:37:13 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/20 15:35:37 by aschoenh         ###   ########.fr       */
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
		if (av[k][1] == '-' && !av[k][2])
			return (k);
		if (av[k][1] == '-' && av[k][2])
			return (ft_ls_error(USAGE, av[k], 1));
		while (av[k][i])
		{
			ret += ft_ls_parse_options(av[k][i], options);
			if (ret % 2 != 0)
				return (ft_ls_error(USAGE, av[k], i));
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
			|| flag == 'r' || flag == 't' || flag == '1')
	{
		if (flag == 's' && (((*options / 100000) + 3) % 5) != 0)
			*options += 200000;
		else if (flag == 'l' && (((*options / 10000) + 3) % 5) != 0)
			*options += 20000;
		else if (flag == 'R' && (((*options / 1000) + 3) % 5) != 0)
			*options += 2000;
		else if (flag == 'a' && (((*options / 100) + 3) % 5) != 0)
			*options += 200;
		else if (flag == 'r' && (((*options / 10) + 3) % 5) != 0)
			*options += 20;
		else if (flag == 't' && (((*options / 1) + 3) % 5) != 0)
			*options += 2;
		else if (flag == '1')
			return (0);
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
		ft_putendl_fd("usage: ft_ls [-alRrst1] [file ...]", 2);
	}
	if (error == ERRNO)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	if (error == USAGE || error == MALL_ERR)
		return (-1);
	return (0);

}
