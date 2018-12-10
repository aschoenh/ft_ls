/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:23:58 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/10 17:08:31 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list_file	*read_directory(char path[PATH_MAX], char file[NAME_MAX + 1]
					, int options)
{
	DIR				*dir;
	struct dirent	*struc;
	int				i;
	t_list_file		lst;

	if ((dir = opendir(path)) == NULL)
	{
		strerror(0, name, 0);
		return (NULL);
	}
	else if (options = 0)
	{
		while (struc = readdir(dir))
			if (((((ft_get_int_len(options) / 100) + 3) % 5) == 0) ||
					struc->d_name[0] != ".")
				ft_ls_get_file(path, file, &lst);
	}
	else
		ft_ls_get_file(path, ".", &lst);
	closedir(dir);
	return (lst);
				 


}

void				ft_ls_display(int options, t_file_list *file, int ac)
{
	t_file_list		*lst;

	lst = file;
	while (lst)
	{
	
	}
}
