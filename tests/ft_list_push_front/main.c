/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:47:47 by kdumarai          #+#    #+#             */
/*   Updated: 2020/01/23 04:22:50 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "libasm_bonus.h"

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
	t_list	*tmp;

	if (argc < 2)
		return EXIT_FAILURE;
	(void)alarm(5);
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
		case 4:
			tmp = ft_list_newnode("libasm or libftasm?!");
			list = ft_list_newnode("welcome42");
			ft_list_push_front(&list, ft_list_newnode("foobar"));
			ft_list_push_front(&list, ft_list_newnode("AssemblyYourself"));
			ft_list_push_front(NULL, tmp);
			ft_print_result(ft_test_list_size(list));
			free(tmp);
			break ;
		case 5:
			list = NULL;
			ft_list_push_front(&list, ft_list_newnode("foobar"));
			ft_print_result(ft_test_list_size(list));
			break ;
		default:
			break ;
	}
	return EXIT_SUCCESS;
}
