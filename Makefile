# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 06:10:18 by kdumarai          #+#    #+#              #
#    Updated: 2020/01/22 01:32:12 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCDIR = srcs
SRCFILES = ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_strdup.s \
			ft_write.s \
			ft_read.s
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

OBJDIR = objs
OBJS = $(SRCS:$(SRCDIR)/%.s=$(OBJDIR)/%.o)

BONUSSRCFILES = bonus/ft_list_size_bonus.s \
				bonus/ft_list_push_front_bonus.s \
				bonus/ft_list_remove_if_bonus.s \
				bonus/ft_list_sort_bonus.s \
				bonus/ft_atoi_base_bonus.s
BONUSSRCS = $(addprefix $(SRCDIR)/, $(BONUSSRCFILES))
BONUSOBJS = $(BONUSSRCS:$(SRCDIR)/%.s=$(OBJDIR)/%.o)

PROJTEXT = \033[1;36m$(basename $(NAME)): \033[0;39m

all: $(NAME)

bonus:
	@ $(MAKE) 'OBJS=$(OBJS) $(BONUSOBJS)' $(NAME)

$(NAME): $(OBJS)
	@ printf "$(PROJTEXT)Linking\n"
	@ ar rcs $@ $(OBJS)
	@ printf "$(PROJTEXT)\033[1;32mLib built at $@\033[0;39m\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@ if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	@ printf "\033[K$(PROJTEXT)Compiling ASM code\033[1;33m $<\033[0;39m\n"
	@ nasm -f macho64 $< -o $@

clean:
	@ rm -rf $(OBJDIR)
	@ printf "$(PROJTEXT)Removed objects\n"

fclean: clean
	@ rm -f $(NAME)
	@ printf "$(PROJTEXT)Removed $(NAME)\n"

re: fclean all

reb: fclean bonus

.PHONY: all bonus clean fclean re reb
