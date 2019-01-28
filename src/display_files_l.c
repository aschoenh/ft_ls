/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:37:20 by aschoenh          #+#    #+#             */
/*   Updated: 2019/01/18 15:39:27 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static char		get_file_type(int m)
{
	if (S_ISREG(m))
		return ('-');
	else if (S_ISDIR(m))
		return ('d');
	else if (S_ISCHR(m))
		return ('c');
	else if (S_ISBLK(m))
		return ('b');
	else if (S_ISFIFO(m))
		return ('p');
	else if (S_ISLNK(m))
		return ('l');
	else if (S_ISSOCK(m))
		return ('s');
	else
		return ('-');
}

static void		get_and_display_chmod(t_file_list *file, char chmod[11])
{
	chmod[0] = get_file_type(file->st_mode);
	chmod[1] = (S_IRUSR & file->st_mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & file->st_mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & file->st_mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & file->st_mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & file->st_mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & file->st_mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & file->st_mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & file->st_mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & file->st_mode) ? 'x' : '-';
	chmod[10] = '\0';
	if (S_ISUID & file->st_mode)
		chmod[3] = chmod[3] == '-' ? 'S' : 's';
	if (S_ISGID & file->st_mode)
		chmod[6] = chmod[6] == '-' ? 'S' : 's';
	if (S_ISVTX & file->st_mode)
		chmod[9] = chmod[9] == '-' ? 'T' : 't';
	ft_putstr(chmod);
}

static void		get_and_display_time(t_file_list *file)
{
	char		*t;
	int			i;

	t = ctime(&(file->time)) + 4;
	if (file->time > time(0) || time(0) - file->time > ((365 / 2) * 86400))
	{
		ft_printf(" %.7s", t);
		i = file->time > time(0) ? 16 : 15;
		while (t[i] == ' ')
			++i;
		ft_putchar(' ');
		while (t[i] != '\n')
		{
			ft_putchar(t[i]);
			++i;
		}
		ft_putchar(' ');
	}
	else
		ft_printf(" %.12s ", t);
}

void			display_ls_lx(t_file_list *file, int size[7], int options)
{
	char		chmod[11];
	char		link[NAME_MAX + 1];

	if (((options / 100000) + 3) % 5 == 0)
		ft_printf("%*hu", size[0], file->st_blocks);
	get_and_display_chmod(file, chmod);
	ft_printf("  %*hu", size[1], file->st_nlink);
	ft_printf(" %-*s", size[2], getpwuid(file->st_uid)->pw_name);
	ft_printf("  %-*s", size[3], getgrgid(file->st_gid)->gr_name);
	if (chmod[0] != 'c' && chmod[0] != 'b')
		ft_printf("  %*lld", size[4], file->st_size);
	else
	{
		ft_printf("  %*d", size[5], major(file->st_rdev));
		ft_printf(", %*d", size[6], minor(file->st_rdev));
	}
	get_and_display_time(file);
	if (chmod[0] != 'l')
		ft_printf("%s", file->name);
	else
	{
		ft_memset(link, 0, NAME_MAX + 1);
		readlink(file->path, link, NAME_MAX + 1);
		ft_printf("%s -> %s", file->name, link);
	}
}
