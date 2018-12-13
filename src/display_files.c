/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:32:02 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/13 18:27:31 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			display_simple_list(t_file_list *lst, int options)
{
	(void) 			options;
	while (lst)
	{
		ft_printf("%s", lst->name);
		lst = lst->next;
	}						// a voir si il faut encore gerer le -a ou si il est deja gere avant
}

static int			get_col_size(t_file_list *lst, int size[7], int options)
{
	int	len_major;
	int	len_minor;
	int	total_blocks;

	len_major = 0;
	len_minor = 0;
	total_blocks = 0;
	while (lst)
	{
		if (((options / 10000) + 3) % 5 == 0)
			size[0] = ft_max(ft_get_int_len(lst->st_blocks), size[0]);
		size[1] = ft_max(ft_get_int_len(lst->st_nlink), size[1]);
		size[2] = ft_max(ft_strlen(getpwuid(lst->st_uid)->pw_name), size[2]);
		size[3] = ft_max(ft_strlen(getgrgid(lst->st_gid)->gr_name), size[3]);
		// is IS_CHR 
		//else
		len_major = ft_max(ft_get_int_len(major(lst->st_rdev)), len_major);
		len_minor = ft_max(ft_get_int_len(minor(lst->st_rdev)), len_minor);
		size[4] = ft_max((len_major + len_minor + 2), size[4]);
		total_blocks += lst->st_blocks;
		lst = lst->next;
	}
	//size?
	return (total_blocks);
}

static void			display_l_list(t_file_list *lst, int options)
{
	int				size[7] = {0};
	int				total_blocks;
	int				isfirst;

	total_blocks = get_col_size(lst, size, options);
	isfirst = 1;
	while (lst)
	{
		if (isfirst == 1)
		{
			ft_printf("total %s\n", total_blocks);
			isfirst--;
		}
		display_ls_lx(lst, size, options);
		ft_putchar('\n');
		lst = lst->next;
	}
}
void				ft_ls_display_files(t_file_list **lst, int options)
{
	ft_sort_list(lst, options);
	if (((options / 10000) + 3) % 5 != 0)
		display_simple_list(*lst, options);
	else
		display_l_list(*lst, options);
}
