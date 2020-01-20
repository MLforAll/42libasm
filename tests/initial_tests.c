/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:19:45 by kdumarai          #+#    #+#             */
/*   Updated: 2020/01/20 23:22:15 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libasm.h"

static char *
gen_random_str(size_t len)
{
	char	c;
	char	*ret;
	size_t	idx;

	ret =  (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return NULL;
	idx = 0;
	while (idx < len)
	{
		c = (char)arc4random_uniform(127);
		if ((c >= '0' && c <= '9') \
			|| (c >= 'a' && c <= 'z') \
			|| (c >= 'A' && c <= 'Z'))
			ret[idx++] = c;
	}
	ret[idx] = '\0';
	return ret;
}

int
main(int ac, const char **av)
{
	char		*s1;
	char		*s2;
	char		buffer[512];
	char		*ptr;

	s1 = (ac < 2) ? gen_random_str(16) : strdup(av[1]);
	s2 = (ac < 2) ? gen_random_str(16) : strdup(av[2]);

	(void) printf("s1: %s\ns2: %s\n\n", s1, s2);

	(void) printf("ft_strlen: %zu\n", ft_strlen(s1));
	(void) printf("strlen   : %zu\n", strlen(s1));

	(void) printf("ft_strcmp: %i\n", ft_strcmp(s1, s2));
	(void) printf("strcmp   : %i\n", strcmp(s1, s2));

	bzero(buffer, sizeof(buffer));
	(void) printf("ft_strcpy: %s\n", ft_strcpy(buffer, s1));
	bzero(buffer, sizeof(buffer));
	(void) printf("strcpy   : %s\n", strcpy(buffer, s1));

	(void) printf("ft_strdup: %s\n", (ptr = ft_strdup(s2)));
	free(ptr);
	(void) printf("strdup   : %s\n", (ptr = strdup(s2)));
	free(ptr);

	free(s1);
	free(s2);

	return 0;
}
