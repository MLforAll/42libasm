/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:47:47 by kelian            #+#    #+#             */
/*   Updated: 2020/01/20 19:18:24 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "libasm.h"
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

static void		ft_list_release(t_list **lst)
{
	t_list	*l;
	t_list	*tmp;

	if (!lst)
		return ;
	l = *lst;
	while (l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
	*lst = NULL;
}

static int		remif_cb(void *a, void *b)
{
	return strcmp((const char *)a, (const char *)b);
}

int				main(int argc, const char *argv[])
{
	t_list	*list;

	if (argc == 1)
		return EXIT_FAILURE;
	alarm(5);
	list = ft_list_newnode("yolo");
	ft_list_push_back(&list, ft_list_newnode("welcome42"));
	ft_list_push_back(&list, ft_list_newnode("foobar"));
	ft_list_push_back(&list, ft_list_newnode("salutLesGars"));
	ft_list_push_back(&list, ft_list_newnode("AssemblyYourself"));
	ft_list_push_back(&list, ft_list_newnode("libasm or libftasm?!"));
	switch (atoi(argv[1]))
	{
		case 1:
			ft_list_remove_if(&list, "yolo", &remif_cb);
			break ;
		case 2:
			ft_list_remove_if(&list, "welcome42", &remif_cb);
			break ;
		case 3:
			ft_list_remove_if(&list, "libasm or libftasm?!", &remif_cb);
			break ;
		case 4:
			ft_list_remove_if(&list, "notfound", &remif_cb);
			break ;
		case 5:
			ft_list_remove_if(&list, "foobar", &remif_cb);
			break ;
		case 6:
			ft_list_release(&list);
			list = ft_list_newnode("say something");
			ft_list_remove_if(&list, "say something", &remif_cb);
			break ;
		default:
			break ;
	}
	ft_print_result(list);
	return EXIT_SUCCESS;
}
