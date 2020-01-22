/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:58:41 by jtoty             #+#    #+#             */
/*   Updated: 2020/01/22 03:03:12 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libasm_bonus.h"

static void		ft_print_result2(char c)
{
	(void)write(1, &c, 1);
}

static void		ft_print_result(int n)
{
	if (n >= 0)
	{
		if (n >= 10)
			ft_print_result(n / 10);
		ft_print_result2(n % 10 + '0');
	}
	else
	{
		ft_print_result2('-');
		if (n <= -10)
			ft_print_result(n / -10);
		ft_print_result2(n % -10 * -1 + '0');
	}
}
static void		base16_tests(uint8_t n)
{
	switch (n)
	{
		case 23:
			ft_print_result(ft_atoi_base("0", 16));
			break ;
		case 24:
			ft_print_result(ft_atoi_base("222:5", 16));
			break ;
		case 25:
			ft_print_result(ft_atoi_base("-1316", 16));
			break ;
		case 26:
			ft_print_result(ft_atoi_base("+224", 16));
			break ;
		case 27:
			ft_print_result(ft_atoi_base("00D646", 16));
			break ;
		case 28:
			ft_print_result(ft_atoi_base("00004A", 16));
			break ;
		case 29:
			ft_print_result(ft_atoi_base("+-36", 16));
			break ;
		case 30:
			ft_print_result(ft_atoi_base("-+30", 16));
			break ;
		case 31:
			ft_print_result(ft_atoi_base("--2F", 16));
			break ;
		case 32:
			ft_print_result(ft_atoi_base("++2F", 16));
			break ;
		case 33:
			ft_print_result(ft_atoi_base("+2F+5", 16));
			break ;
		case 34:
			ft_print_result(ft_atoi_base("-2F-5", 16));
			break ;
		case 35:
			ft_print_result(ft_atoi_base("\e1DB", 16));
			break ;
		case 36:
			ft_print_result(ft_atoi_base("\t\n\r\v\f  1D5 \n", 16));
			break ;
		case 37:
			ft_print_result(ft_atoi_base("-80000000", 16));
			break ;
		case 38:
			ft_print_result(ft_atoi_base("7FFFFFFF", 16));
			break ;
		case 39:
			ft_print_result(ft_atoi_base("\t\n\r\v\fZ1D5 \n", 16));
			break ;
		case 40:
			ft_print_result(ft_atoi_base("\n\n\n  -2E\b9 \n5d6", 16));
			break ;
		case 41:
			ft_print_result(ft_atoi_base("", 16));
			break ;
		default:
			break ;
	}
}

static void		base10_tests(uint8_t n)
{
	switch (n)
	{
		case 1:
			ft_print_result(ft_atoi_base("0", 10));
			break ;
		case 2:
			ft_print_result(ft_atoi_base("546:5", 10));
			break ;
		case 3:
			ft_print_result(ft_atoi_base("-4886", 10));
			break ;
		case 4:
			ft_print_result(ft_atoi_base("+548", 10));
			break ;
		case 5:
			ft_print_result(ft_atoi_base("054854", 10));
			break ;
		case 6:
			ft_print_result(ft_atoi_base("000074", 10));
			break ;
		case 7:
			ft_print_result(ft_atoi_base("+-54", 10));
			break ;
		case 8:
			ft_print_result(ft_atoi_base("-+48", 10));
			break ;
		case 9:
			ft_print_result(ft_atoi_base("--47", 10));
			break ;
		case 10:
			ft_print_result(ft_atoi_base("++47", 10));
			break ;
		case 11:
			ft_print_result(ft_atoi_base("+47+5", 10));
			break ;
		case 12:
			ft_print_result(ft_atoi_base("-47-5", 10));
			break ;
		case 13:
			ft_print_result(ft_atoi_base("\e475", 10));
			break ;
		case 14:
			ft_print_result(ft_atoi_base("\t\n\r\v\f  469 \n", 10));
			break ;
		case 15:
			ft_print_result(ft_atoi_base("-2147483648", 10));
			break ;
		case 16:
			ft_print_result(ft_atoi_base("2147483647", 10));
			break ;
		case 17:
			ft_print_result(ft_atoi_base("\t\n\r\v\fd469 \n", 10));
			break ;
		case 18:
			ft_print_result(ft_atoi_base("\n\n\n  -46\b9 \n5d6", 10));
			break ;
		case 19:
			ft_print_result(ft_atoi_base("", 10));
			break ;
		case 20:
			ft_print_result(ft_atoi_base(NULL, 10));
			break ;
		case 21:
			ft_print_result(ft_atoi_base("42", 42));
			break ;
		case 22:
			ft_print_result(ft_atoi_base(NULL, 42));
			break ;
		default:
			break ;
	}
}

int				 main(int argc, const char *argv[])
{
	uint8_t	n;

	if (argc < 2)
		return EXIT_FAILURE;
	(void)alarm(5);
	n = (uint8_t)atoi(argv[1]);
	if (n < 23)
		base10_tests(n);
	else
		base16_tests(n);
	return EXIT_SUCCESS;
}
