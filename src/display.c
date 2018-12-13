/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:23:58 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/13 18:23:06 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file_list	*read_directory(char path[PATH_MAX], char file[NAME_MAX + 1]
					, int options)
{
	DIR				*dir;
	struct dirent	*struc;
	t_file_list		*lst;

	if ((dir = opendir(path)) == NULL)
	{
		ft_ls_error(0, file, 0);
		return (NULL);
	}
	else if (options == 0)
	{
		while ((struc = readdir(dir)))
			if (((((ft_get_int_len(options) / 100) + 3) % 5) == 0) ||
					struc->d_name[0] != '.')
				ft_ls_get_file(path, file, &lst);
	}
	else
		ft_ls_get_file(path, ".", &lst);
	closedir(dir);
	return (lst);
}

static void			display_path(char *path, int ac, int *isfirst)
{
	if (ac > 1)
	{
		if (isfirst == 0)
		{
			ft_printf("%s:\n", path);
			isfirst++;
		}
		else
			ft_printf("\n%s:\n", path);
	}
}

void				ft_ls_display(int options, t_file_list *file, int ac)
{
	t_file_list		*lst;
	int				isfirst;

	isfirst = 0;
	lst = file;
//	if ((((lst->st_mode / 1000) + 3) % 5) == 0 && !isfirst)
//		return ;
	while (lst)
	{
		if (S_ISDIR(lst->st_mode)) /* . et .. ? */
		{
			display_path(lst->path, ac, &isfirst);
			if ((file = read_directory(lst->path, lst->name, options)))
			{
				ft_ls_display_files(&lst, options);
			//	ft_ls_display(options, lst, 0);
				ft_list_clear(&lst);
			}
		}
		lst = lst->next;
	}
}
