/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:57:21 by kdumarai          #+#    #+#             */
/*   Updated: 2020/01/20 03:19:45 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define C_CHARSET_UP	"0123456789ABCDEF"
#define C_CHARSET_LC	"0123456789abcdef"

int
ft_atoi_base(const char *str, int base);

static const char *
ft_strnchr(const char *s, char c, size_t n)
{
	while (n-- && *s)
	{
		if (*s == c)
			return s;
		s++;
	}
	return NULL;
}

inline static uint8_t
ft_atoi_is_whitespace(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' \
					|| c == '\r';
}

inline static uint8_t
ft_atoi_is_digit(char c, int base)
{
	return ft_strnchr(C_CHARSET_LC, c, base) \
			|| ft_strnchr(C_CHARSET_UP, c, base);
}

inline static uint8_t
ft_atoi_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'z')
		return c - ('a' - 10);
	return c - ('A' - 10);
}

int
ft_atoi_base_c(const char *str, int base)
{
	uint8_t			neg;
	unsigned int	i;
	long long		ret;

	if (base < 2 || base > 16)
		return (0);
	i = 0;
	ret = 0;
	while (str[i] != '+' && str[i] != '-' && ft_atoi_is_whitespace(str[i]))
		i++;
	if (!str[i])
		return (0);
	neg = (str[i] == '-');
	if (!ft_atoi_is_digit(str[i], base))
	{
		if (str[i] != '+' && !neg)
			return (0);
		i++;
	}
	while (str[i] && ft_atoi_is_digit(str[i], base))
		ret = ret * base + ft_atoi_char_to_int(str[i++]);
	if (neg)
		ret = -ret;
	return ((int)ret);
}

int
main(int ac, const char **av)
{
	if (ac < 3)
		return 1;
	int base = atoi(av[2]);
	(void)printf("c  : %i\nasm: %i\n", \
		ft_atoi_base_c(av[1], base), \
		ft_atoi_base(av[1], base));
	return 0;
}
