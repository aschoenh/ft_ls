/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:02:30 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/07 18:03:08 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file_list	get_file(char *file, char *path, struct stat info)
{
	t_file			*elem;

	if (!(elem = (t_file_list*)ft_memalloc(sizeof(t_file_list)))
			|| (!(elem->name = ft_strdup(file))))
		ls_error(XXX, XXX);
	elem->st_nlink = stat->st_nlink;
	elem->st_uid = stat->st_uid;
	elem->st_gid = stat->st_gid;
	elem->st_mode = stat->st_mode;
	elem->st_size = stat->st_size;
	elem->st_rdev = stat->st_rdev;
	elem->time = stat->st_mtimespec.tv_sec;
	elem->time_set = stat->st_mtimespec.tv_nsec;
	elem->st_blocks = stat->st_blocks;
	ft_ls_path(path, name, elem->path);
	elem->next = NULL;
	return (new);
}

char				*ft_ls_get_path(char *file)
{
readdir
	elem->d_type = stat->d_type;
}

t_list				ft_ls_get_file(char *file, t_file_list *lst)
{
	char			path[PATH_MAX];
	struct stat		info;

	if (!(path = ft_ls_get_path(file)))
	{
		ls_error(XXX, file, 0);
		return (-1);
	}
	if ((lstat(path, &info) == -1))
		return (-1);
	if (!*lst)
		*lst = get_file(file, path, &info);
	else
	{
		while ((*lst)->next)
			lst = &((*lst)->next);
		(*lst)->next = get_file(file, path, &info);
	}
	return (1);
}
