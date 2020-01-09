/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelian <kelian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:47:47 by kelian            #+#    #+#             */
/*   Updated: 2020/01/09 16:14:18 by kelian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libasm.h"

static void		ft_print_result(int n)
{
	char	c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	(void)write(1, &c, 1);
}

static t_list	*ft_list_newnode(void *data)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	ret->data = data;
	ret->next = NULL;
	return ret;
}

static size_t	ft_test_list_size(t_list *lst)
{
	size_t	ret;

	ret = 0;
	while (lst)
	{
		lst = lst->next;
		ret++;
	}
	return ret;
}

int				main(int argc, const char *argv[])
{
	t_list	*list;

	if (argc == 1)
		return EXIT_FAILURE;
	alarm(5);
	switch (atoi(argv[1]))
	{
		case 1:
			list = ft_list_newnode("yolo");
			ft_list_push_front(&list, ft_list_newnode("welcome42"));
			ft_list_push_front(&list, ft_list_newnode("foobar"));
			ft_list_push_front(&list, ft_list_newnode("salutLesGars"));
			ft_list_push_front(&list, ft_list_newnode("AssemblyYourself"));
			ft_list_push_front(&list, ft_list_newnode("libasm or libftasm?!"));
			ft_print_result(ft_test_list_size(list));
			break ;
		case 2:
			list = ft_list_newnode("yolo");
			ft_list_push_front(&list, ft_list_newnode("libasm or libftasm?!"));
			ft_print_result(ft_test_list_size(list));
			break ;
		case 3:
			list = ft_list_newnode("welcome42");
			ft_list_push_front(&list, ft_list_newnode("foobar"));
			ft_list_push_front(&list, ft_list_newnode("AssemblyYourself"));
			ft_list_push_front(&list, ft_list_newnode("libasm or libftasm?!"));
			ft_print_result(ft_test_list_size(list));
			break ;
		default:
			break ;
	}
	return EXIT_SUCCESS;
}
