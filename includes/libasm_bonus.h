/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 04:10:21 by kdumarai          #+#    #+#             */
/*   Updated: 2020/01/20 22:40:22 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <string.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

size_t			ft_list_size(t_list *list);
void			ft_list_push_front(t_list **head, t_list *e);
void			ft_list_remove_if(t_list **head, \
								void *data, \
								int (*cmp)(void *, void *));
void			ft_list_sort(t_list **head, int (*cmp)(void *, void *));

int				ft_atoi_base(const char *s, int base);

#endif
