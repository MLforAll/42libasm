/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:47:47 by kdumarai          #+#    #+#             */
/*   Updated: 2020/01/22 01:50:42 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "libasm_bonus.h"

static void		ft_print_result(t_list *lst)
{
	if (!lst)
	{
		(void)puts("ft_print_result: empty");
		return ;
	}
	while (lst)
	{
		(void)puts((const char *)lst->data);
		lst = lst->next;
	}
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

static void		ft_list_push_back(t_list **lst, t_list *node)
{
	t_list	*bw;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	bw = *lst;
	while (bw->next)
		bw = bw->next;
	bw->next = node;
}

static int		list_sort_cb(void *a, void *b)
{
	return strcmp((const char *)a, (const char *)b);
}

int				main(int argc, const char *argv[])
{
	t_list	*list;
	t_list	**ptr;
	int		(*cbf)(void *, void *);

	if (argc < 2)
		return EXIT_FAILURE;
	(void)alarm(5);
	list = NULL;
	ptr = &list;
	cbf = &list_sort_cb;
	switch (atoi(argv[1]))
	{
		case 1:
			list = ft_list_newnode("one");
			ft_list_push_back(&list, ft_list_newnode("two"));
			ft_list_push_back(&list, ft_list_newnode("three"));
			break ;
		case 2:
			list = ft_list_newnode("def");
			ft_list_push_back(&list, ft_list_newnode("bcd"));
			ft_list_push_back(&list, ft_list_newnode("aabc"));
			ft_list_push_back(&list, ft_list_newnode("aaa"));
			break ;
		case 3:
			list = ft_list_newnode("yolo");
			ft_list_push_back(&list, ft_list_newnode("welcome42"));
			ft_list_push_back(&list, ft_list_newnode("foobar"));
			ft_list_push_back(&list, ft_list_newnode("salutLesGars"));
			ft_list_push_back(&list, ft_list_newnode("AssemblyYourself"));
			ft_list_push_back(&list, ft_list_newnode("libasm or libftasm?!"));
			break ;
		case 4:
			break ;
		case 5:
			cbf = NULL;
			list = ft_list_newnode("one");
			ft_list_push_back(&list, ft_list_newnode("two"));
			break ;
		case 6:
			cbf = NULL;
			break ;
		case 7:
			list = ft_list_newnode("one");
			break ;
		case 8:
			ptr = NULL;
			break ;
		default:
			break ;
	}
	ft_list_sort(&list, cbf);
	ft_print_result(list);
	return EXIT_SUCCESS;
}
