# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kelian <kelian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 06:10:18 by kdumarai          #+#    #+#              #
#    Updated: 2020/01/09 16:22:48 by kelian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCDIR = srcs
SRCFILES = ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_strdup.s \
			ft_write.s \
			ft_read.s \
			ft_list_size.s \
			ft_list_push_front.s \
			ft_list_remove_if.s
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

OBJDIR = objs/lib
OBJS = $(SRCS:$(SRCDIR)/%.s=$(OBJDIR)/%.o)

PROJTEXT = \033[1;36m$(basename $(NAME)): \033[0;39m

all: $(NAME)

$(NAME): $(OBJS)
	@ printf "$(PROJTEXT)Linking\n"
	@ ar rcs $@ $(OBJS)
	@ printf "$(PROJTEXT)\033[1;32mLib built at $@\033[0;39m\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@ if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	@ printf "\033[K$(PROJTEXT)Compiling ASM code\033[1;33m $<\033[0;39m\n"
	@ nasm -f macho64 $< -o $@

clean:
	@ rm -rf $(dir $(OBJDIR))
	@ printf "$(PROJTEXT)Removed objects\n"

fclean: clean
	@ rm -f $(NAME)
	@ printf "$(PROJTEXT)Removed $(NAME)\n"

re: fclean all

.PHONY: all clean fclean re
