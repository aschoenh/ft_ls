/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:39:44 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/11 19:42:37 by aschoenh         ###   ########.fr       */
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
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>
# include <stdlib.h>

enum				{ERRNO, USAGE, MALL_ERR};

typedef struct		s_file_list
{
char				name[NAME_MAX + 1]; /* nom du fichier */
char				path[PATH_MAX]; /*full path du fichier*/
unsigned char		d_type;      /* type du fichier */
int					st_mode;     /* Protection */
uid_t				st_uid;      /* UID propriétaire */
gid_t				st_gid;		/* GIF proprietaire */
dev_t				st_rdev;   /* ID périphérique (si fichier spécial) */
off_t				st_size;     /* Taille totale en octets */
long				time;      /* deriere modif, a recup avec ctime*/
time_t				time_set;
nlink_t   			st_nlink;    /* Nb liens matériels */
blkcnt_t			st_blocks;   /* Nombre de blocs alloués */
struct s_file_list	*next;
}					t_file_list;

/***********/
/**PARSING**/
/***********/

int					ft_ls_parsing(int ac, char **av, int *options);
int					ft_ls_error(int error, char *s, int index);
int					ft_ls_parse_options(char flag, int *options);

/***********/
/***LISTS***/
/***********/

t_file_list			*ft_ls_list_files(char **av, int c, int i);
int					ft_ls_get_file(char path[PATH_MAX], char file[NAME_MAX + 1],
						t_file_list **lst);


/***********/
/**DISPLAY**/
/***********/

void				ft_ls_display(int options, t_file_list *file, int ac);
void				display_files(t_file_list **file, int options);
void				display_rest(t_file_list **file, int options);

/***********/
/***SORT****/
/***********/

void				ft_sort_list(t_file_list **lst, int options);


/***********/
/***UTILS***/
/***********/

void				ft_list_clear(t_file_list **beggin_list);
int					ft_list_longest_name(t_file_list **lst);
t_file_list			*ft_lst_swap(t_file_list *file1, t_file_list *file2);
int					ft_get_int_len(int n);

# endif
