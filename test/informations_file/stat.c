/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:42:04 by aschoenh          #+#    #+#             */
/*   Updated: 2018/12/18 21:25:08 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>



int			main(int ac, char **av)
{
	char			*fd = av[1];
	struct stat		buf;
	struct passwd	*uid;
	struct group	*gid;
	char			*ct;
	char			*cta;
	char			*ctc;

	if (ac == 2)
	{
		stat(fd, &buf);
		uid = getpwuid(buf.st_uid);
		gid = getgrgid(buf.st_gid);
		
		ct = ctime(&buf.st_mtime);
		ct += 4;
		cta = ctime(&buf.st_atime);
		ctc = ctime(&buf.st_ctime);
		printf("Informations uid (getpwuid(buf.st_uid):\n\nUsername : %s\n", uid->pw_name);
		printf("User Passwd : %s\n", uid->pw_passwd);
		printf("pw_uid : %d\n", uid->pw_uid);
		printf("pw_gid : %d\n", uid->pw_gid);
		printf("user info: %s\n", uid->pw_gecos);
		printf("home directory: %s\n", uid->pw_dir);
		printf("shell programm: %s\n", uid->pw_shell);

		printf("\n\nInformations gid (getgrid(buf.st_gid):\n\nGroupname : %s\n", gid->gr_name);
		printf("Group Passwd : %s\n", gid->gr_passwd);
		printf("group ID : %d\n\n\n", gid->gr_gid);
/*		printf("membre : %s", gid->gr_mem);
*/
		printf("Nombres de liens : %d\n", buf.st_nlink);
		if (S_ISREG(buf.st_mode))
			printf("Ceci est un fichier. \n");
		if (S_ISDIR(buf.st_mode))
			printf("Ceci est un dossier. \n");
		if (S_ISCHR(buf.st_mode))
			printf("Ceci est un periph en mode carac. \n");
		printf("\n\n Time last modif :%.12s\n", ct);

/*		printf("Time last access :%s\n", cta);
		printf("Time last change state:%s\n", ctc);
*/
		printf("Mode : %hu\n", buf.st_mode);

		printf("Taille : %lld octets", buf.st_size);
	}
	return (0);
}
