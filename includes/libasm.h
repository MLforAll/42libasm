/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelian <kelian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 00:38:12 by kdumarai          #+#    #+#             */
/*   Updated: 2020/01/09 16:22:08 by kelian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <string.h>

size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);

ssize_t			ft_write(int fd, const void *buff, size_t n);
ssize_t			ft_read(int fd, void *buff, size_t n);

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

#endif
