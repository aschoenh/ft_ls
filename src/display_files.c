/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:32:02 by aschoenh          #+#    #+#             */
/*   Updated: 2019/01/17 17:43:58 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			display_simple_list(t_file_list *lst, int count)
{
	int				i;
	t_file_list		*lst1;

	lst1 = lst;
	i = 0;
	while (lst && i != count)
	{
		ft_printf("%s\n", lst->name);
		lst = lst->next;
		i++;
	}
	if (lst && count)
		ft_putchar('\n');
}

static int			get_col_size(t_file_list *lst, int size[7], int options)
{
	int	total_blocks;
	int	len;

	total_blocks = 0;
	while (lst)
	{
		if (((options / 10000) + 3) % 5 == 0)
			size[0] = ft_max(ft_get_int_len(lst->st_blocks), size[0]);
		size[1] = ft_max(ft_get_int_len(lst->st_nlink), size[1]);
		size[2] = ft_max(ft_strlen(getpwuid(lst->st_uid)->pw_name), size[2]);
		size[3] = ft_max(ft_strlen(getgrgid(lst->st_gid)->gr_name), size[3]);
		if (!S_ISCHR(lst->st_mode))
			len = ft_get_int_len(lst->st_size);
		else
		{
			size[5] = ft_max(ft_get_int_len(major(lst->st_rdev)), size[5]);
			size[6] = ft_max(ft_get_int_len(minor(lst->st_rdev)), size[6]);
			size[4] = ft_max((size[5] + size[6] + 2), size[4]);
		}
		size[4] = ft_max(len, size[4]);
		total_blocks += lst->st_blocks;
		lst = lst->next;
	}
	size[5] = ft_max(size[4] - size[6] - 1, size[5]);
	return (total_blocks);
}

static void			display_l_list(t_file_list *lst, int options,
						int count, int *isfirst)
{
	int				size[7];
	int				total_blocks;
	int				i;

	i = 7;
	while (i >= 0)
		size[i--] = 0;
	total_blocks = get_col_size(lst, size, options);
	i = 0;
	while (lst && i != count)
	{
		if (i + 1 > count)
			(*isfirst)++;
		if (*isfirst == 1 && i != count)
		{
			ft_printf("total %d\n", total_blocks);
		}
		display_ls_lx(lst, size, options);
		ft_putchar('\n');
		lst = lst->next;
		i++;
	}
	if (lst && count)
		ft_putchar('\n');
}

void				ft_ls_display_files(t_file_list **lst, int options,
						int count)
{
	int			isfirst;

	isfirst = 0;
	ft_sort_list(lst, options, count);
	if (((options / 10000) + 3) % 5 != 0)
	{
		display_simple_list(*lst, count);
	}
	else
		display_l_list(*lst, options, count, &isfirst);
}
