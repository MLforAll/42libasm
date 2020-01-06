/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:04:46 by jtoty             #+#    #+#             */
/*   Updated: 2020/01/06 17:11:57 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libasm.h"

static void		check_strcpy(char *dest, char *src, int len)
{
	if (dest != ft_strcpy(dest, src))
		(void)write(1, "dest's adress was not returned\n", 31);
	(void)write(1, dest, len);
}

int		main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;
	size_t	len;

	alarm(5);
	len = 15;
	if (!(dest = (char *)malloc(sizeof(*dest) * len)) || argc == 1)
		return (0);
	(void)memset(dest, 0, len);
	(void)memset(dest, 'f', 9);
	if ((arg = atoi(argv[1])) == 1)
		check_strcpy(dest, "lorem", len);
	else if (arg == 2)
		check_strcpy(dest, "lorem ipsum", len);
	else if (arg == 3)
		check_strcpy(dest, "", len);
	free(dest);
	return (0);
}
