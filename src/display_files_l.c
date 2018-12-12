/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:37:20 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/12 18:57:26 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
