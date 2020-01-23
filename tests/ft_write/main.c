/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 03:46:38 by kdumarai          #+#    #+#             */
/*   Updated: 2020/01/23 04:57:21 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "libasm.h"

#define PIPE_WFD	1
#define PIPE_RFD	0

static char *
buffer_from_file(const char *path, size_t *outfsz)
{
	int			fd;
	char		*ret;
	struct stat	st;

	(void)stat(path, &st);
	fd = open(path, O_RDONLY);
	ret = (char *)malloc(st.st_size);
	(void)read(fd, ret, st.st_size);
	(void)close(fd);
	if (outfsz)
		*outfsz = st.st_size;
	return ret;
}

static void
ft_print_result(const char *path, const char *s, size_t wn)
{
	int		pfd[2];
	ssize_t	ret;
	size_t	tmp;
	char	*buffer;
	char	*sb;

	(void)pipe(pfd);
	if (path)
	{
		tmp = 0;
		sb = buffer_from_file(path, &tmp);
		if (wn > tmp)
			wn = tmp;
	}
	else
		sb = NULL;
	errno = 0;
	ret = ft_write(pfd[PIPE_WFD], sb ? sb : s, wn);
	(void)printf("ret: %li\nerrno: %i\n", ret, errno);
	(void)close(pfd[PIPE_WFD]);
	buffer = (char *)malloc(wn);
	bzero(buffer, wn);
	if ((ret = read(pfd[PIPE_RFD], buffer, wn)) > 0)
	{
		(void)write(STDOUT_FILENO, "buffer: ", 8);
		(void)write(STDOUT_FILENO, buffer, ret);
		(void)write(STDOUT_FILENO, "\n", 1);
	}
	(void)close(pfd[PIPE_RFD]);
	free(buffer);
	if (sb)
		free(sb);
}

int
main(int ac, const char **av)
{
	if (ac < 2)
		return EXIT_FAILURE;
	setbuf(stdout, NULL);
	switch (atoi(av[1]))
	{
		case 1:
			ft_print_result(NULL, "I want to break free", 15);
			break ;
		case 2:
			ft_print_result(NULL, NULL, 15);
			break ;
		case 3:
			ft_print_result(NULL, "Hello guys", 0);
			break ;
		case 4:
			ft_print_result("resource_42logo.svg", NULL, 2142);
			break ;
		default:
			break ;
	}
	return EXIT_SUCCESS;
}
