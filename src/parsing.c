/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:37:13 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/12 16:56:54 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

int		ft_ls_parsing(int ac, char **av, int *options)
{
	int			ret;
	int			i;
	(void)		ac;

	ret = 900000;
	*options = 0;
	i = 1;
	if (av[1][0] == '-' && (av[1][1])) // flags separes
	{
		while (av[1][i])
		{
			ret += ft_ls_parse_options(av[1][i], options);
			if (ret % 2 != 0)
				return (ft_ls_error(USAGE, av[1], i));
			i++;
		}
	}
	return (i - 1);
}

int		ft_ls_parse_options(char flag, int *options)
{
	if (flag == 'l')
		*options += 20000;
	else if (flag == 'R')
		*options += 2000;
	else if (flag == 'a')
		*options += 200;
	else if (flag == 'r')
		*options += 20;
	else if (flag == 't')
		*options += 2;
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
		ft_putendl_fd("usage: ft_ls [-alRrt] [file ...]", 2);
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
