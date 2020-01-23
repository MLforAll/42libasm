/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 03:46:38 by kdumarai          #+#    #+#             */
/*   Updated: 2020/01/23 04:20:05 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "libasm.h"

#define PIPE_WFD	1
#define PIPE_RFD	0

static void
ft_print_result(const char *path, const char *s, size_t rn)
{
	int		fd;
	int		pfd[2];
	ssize_t	ret;
	char	*buffer;

	fd = -1;
	if (path)
		fd = open(path, O_RDONLY);
	else if (s)
	{
		(void)pipe(pfd);
		(void)write(pfd[PIPE_WFD], s, strlen(s));
		(void)close(pfd[PIPE_WFD]);
		fd = pfd[PIPE_RFD];
	}
	buffer = (char *)malloc(rn);
	bzero(buffer, rn);
	errno = 0;
	ret = ft_read(fd, buffer, rn);
	(void)printf("ret: %li\nerrno: %i\n", ret, errno);
	if (ret > 0)
	{
		(void)write(STDOUT_FILENO, "buffer: ", 8);
		(void)write(STDOUT_FILENO, buffer, ret);
		(void)write(STDOUT_FILENO, "\n", 1);
	}
	(void)close(fd);
	free(buffer);
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
			ft_print_result(NULL, "Je veux lire bcp trop ;)", 4221);
			break ;
		case 5:
			ft_print_result("resource_42logo.png", NULL, 22942);
			break ;
		default:
			break ;
	}
	return EXIT_SUCCESS;
}
