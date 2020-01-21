/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:04:55 by jtoty             #+#    #+#             */
/*   Updated: 2020/01/21 22:02:40 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libasm.h"

static void		ft_print_result(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	(void)write(1, s, len);
}

static void		check_strdup(const char *str)
{
	char	*str_dup;

	if (!(str_dup = ft_strdup(str)))
	{
		ft_print_result("NULL");
		return ;
	}
	ft_print_result(str_dup);
	if (str_dup == str)
		ft_print_result("\nstr_dup's adress == str's adress");
	else
		free(str_dup);
}

int				main(int argc, const char *argv[])
{
	(void)alarm(5);
	if (argc < 2)
		return EXIT_FAILURE;
	switch (atoi(argv[1]))
	{
		case 1:
			check_strdup("lorem ipsum dolor sit amet");
			break ;
		case 2:
			check_strdup(NULL);
			break ;
		default:
			break ;
	}
	return EXIT_SUCCESS;
}
