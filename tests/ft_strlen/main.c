/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:58:17 by jtoty             #+#    #+#             */
/*   Updated: 2020/01/21 21:35:46 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libasm.h"

static void		ft_print_result(size_t n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	(void)write(1, &c, 1);
}

int				main(int argc, const char *argv[])
{
	if (argc < 2)
		return EXIT_FAILURE;
	(void)alarm(5);
	switch (atoi(argv[1]))
	{
		case 1:
			ft_print_result(ft_strlen("Hello !"));
			break ;
		case 2:
			ft_print_result(ft_strlen("1"));
			break ;
		case 3:
			ft_print_result(ft_strlen("lorem\tipsum\tdolor\nsit\namet\n"));
			break ;
		case 4:
			ft_print_result(ft_strlen(""));
			break ;
		case 5:
			ft_print_result(ft_strlen("\n\n\f\r\t"));
			break ;
		case 6:
			ft_print_result(ft_strlen("   "));
			break ;
		case 7:
			ft_print_result(ft_strlen(NULL));
			break ;
		default:
			break ;
	}
	return EXIT_SUCCESS;
}
