/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:04:55 by jtoty             #+#    #+#             */
/*   Updated: 2020/01/06 16:40:16 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libasm.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	(void)write(1, s, len);
}

int				main(int argc, const char *argv[])
{
	const char	*str = "lorem ipsum dolor sit amet";
	char		*str_dup;

	alarm(5);
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
			ft_print_result(str_dup);
		if (str_dup == str)
			ft_print_result("\nstr_dup's adress == str's adress");
		else
			free(str_dup);
	}
	return (0);
}
