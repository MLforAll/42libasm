/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:04:46 by jtoty             #+#    #+#             */
/*   Updated: 2020/01/21 22:29:16 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libasm.h"

static void		check_strcpy(char *dest, const char *src, int len)
{
	if (dest != ft_strcpy(dest, src))
		(void)write(1, "dest's adress was not returned\n", 31);
	if (dest)
		(void)write(1, dest, len);
	else
		(void)write(1, "NULL", 4);
}

int		main(int argc, const char *argv[])
{
	char	dest[15];
	size_t	len;
	int		arg;

	if (argc < 2)
		return EXIT_FAILURE;
	(void)alarm(5);
	len = sizeof(dest) / sizeof(*dest);
	(void)memset(dest, 0, len);
	(void)memset(dest, 'f', 9);
	if ((arg = atoi(argv[1])) == 1)
		check_strcpy(dest, "lorem", len);
	else if (arg == 2)
		check_strcpy(dest, "lorem ipsum", len);
	else if (arg == 3)
		check_strcpy(dest, "", len);
	else if (arg == 4)
		check_strcpy(dest, NULL, len);
	else if (arg == 5)
		check_strcpy(NULL, "yolo", len);
	else if (arg == 6)
		check_strcpy(NULL, NULL, len);
	return EXIT_SUCCESS;
}
