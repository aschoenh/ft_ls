/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:23:58 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/14 19:29:11 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file_list	*read_directory(char path[PATH_MAX], char file[NAME_MAX + 1]
					, int options)
{
	DIR				*dir;
	struct dirent	*struc;
	t_file_list		*new;

	new = NULL;
	if ((dir = opendir(path)) == NULL)
		ft_ls_error(0, file, 0);
	else
	{
//		ft_printf("%d", options);
		while ((struc = readdir(dir)))
		{
			//ft_printf("%s||", struc->d_name);
			if ((((((options) / 100) + 3) % 5) == 0) ||
					struc->d_name[0] != '.')
			{
				ft_ls_get_file(path, struc->d_name, &new);
//				ft_printf("   |   ");
			}
		}
	}
	if (dir)
		closedir(dir);
	return (new);
}

static void			display_path(char *path, int ac, int *isfirst)
{
	(void) path;
	if (ac > 2)
	{
		if (*isfirst == 0)
		{
			ft_printf("%s:\n", path);
			(*isfirst)++;
		}
		else
			ft_printf("\n%s:\n", path);

	}
}

void				ft_ls_display(int options, t_file_list *file, int ac, int isfirst)
{
	t_file_list		*lst;

	lst = file;
	if ((((options / 1000) + 3) % 5) != 0 && !isfirst)
		return ;
	else
	{
		while (lst)
		{
			if ((S_ISDIR(lst->st_mode)) && (isfirst || ft_strcmp(lst->name, ".")) && ft_strcmp(lst->name, ".."))
			{
				display_path(lst->path, ac, &isfirst);
				if ((file = read_directory(lst->path, lst->name, options)))
				{
					ft_ls_display_files(&file, options);
					ft_ls_display(options, file, -1, 0);
					//ft_list_clear(&file);
				}
			}
			lst = lst->next;
		}
	}
}
