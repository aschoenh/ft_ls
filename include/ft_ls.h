/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:39:44 by aschoenh          #+#    #+#             */
/*   Updated: 2019/01/17 17:18:07 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_file_list
{
	char				name[NAME_MAX + 1];
	char				path[PATH_MAX];
	unsigned char		d_type;
	int					st_mode;
	uid_t				st_uid;
	gid_t				st_gid;
	dev_t				st_rdev;
	off_t				st_size;
	long				time;
	time_t				time_set;
	nlink_t				st_nlink;
	blkcnt_t			st_blocks;
	struct s_file_list	*next;
}						t_file_list;

enum					{ERRNO, USAGE, MALL_ERR};
int						ft_ls_parsing(int ac, char **av, int *options);
int						ft_ls_error(int error, char *s, int index);
int						ft_ls_parse_options(char flag, int *options);
t_file_list				*ft_ls_list_files(char **av, int c, int *i,
							int isfirst);
int						ft_ls_get_file(char path[PATH_MAX],
							char file[NAME_MAX + 1],
							t_file_list **lst);
void					ft_ls_display(int options, t_file_list *file, int ac,
							int isfirst);
void					ft_ls_display_files(t_file_list **file, int options,
							int count);
void					display_rest(t_file_list **file, int options);
void					display_ls_lx(t_file_list *file, int size[7],
							int options);
void					ft_sort_list(t_file_list **lst, int options, int count);
int						sort_args(char **av, int ac, int i, int *count);
void					ft_list_merge(t_file_list **begin_list1,
							t_file_list *begin_list2);
void					ft_list_clear(t_file_list **beggin_list);
int						ft_list_longest_name(t_file_list **lst);
t_file_list				*ft_lst_swap(t_file_list *file1, t_file_list *file2);
int						ft_get_int_len(int n);
int						ft_max(int a, int b);

# endif
