/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:58:07 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/04 17:50:06 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int			main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*struc;
	int				i;

	if (ac != 2)
	{
		printf("error");
		return (0);
	}
	if ((dir = opendir(av[1])) == NULL)
	{
		perror("opendir");
		return (0);
	}
	printf("Directory stream open\n");
	i = 0;
	while ((struc = readdir(dir)) != NULL)
		{
			printf("%s\n", struc->d_name);
			i++;
		}
	printf("\n\n%d %s", i, "files read\n");
	if (closedir(dir) == -1)
	{
		perror("closedir");
		return (0);
	}
	printf("Directory stream close\n");
	return (1);
}

