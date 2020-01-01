# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 06:10:18 by kdumarai          #+#    #+#              #
#    Updated: 2020/01/01 21:59:52 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCDIR = srcs
SRCFILES = ft_strlen.s
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

OBJDIR = objs
OBJS = $(SRCS:$(SRCDIR)/%.s=$(OBJDIR)/%.o)

NSRC = $(shell echo "$(SRCS)" | awk '{print NF}')
ifeq ($(shell which bc >/dev/null && which awk >/dev/null && echo true),true)
	CSRC = 1
else
	CSRC = 0
endif

PROJTEXT = \033[1;34mlibasm: \033[0;39m

all: $(NAME)

$(NAME): $(NAME)
	@ printf "\033[K$(PROJTEXT)Compiling\n"
	@ printf "$(PROJTEXT)Linking\n"
	@ ar rcs $@ $(OBJS)
	@ printf "$(PROJTEXT)\033[1;32mLib built at $@\033[0;39m\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@ if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	@ printf "\033[K$(PROJTEXT)Compiling \033[1;33m$<"
ifneq ($(CSRC),0)
	@ printf " %.0s" {1..$(shell expr 40 - $(shell printf "$<" | wc -m))}
	@ export LC_ALL=C; printf "\033[1;34m[%3.0f%%]" "$(shell bc <<< "scale=1; $(CSRC) / $(NSRC) * 100")"
	@ $(eval CSRC = $(shell expr $(CSRC) + 1))
endif
	@ printf "\033[0;39m\r"
	@ nasm -f macho64 $< -o $@

clean:
	@ rm -rf $(OBJDIR)
	@ printf "$(PROJTEXT)Removed objects\n"

fclean: clean
	@ rm -f $(NAME)
	@ printf "$(PROJTEXT)Removed $(NAME)\n"

re: fclean all

.PHONY: all clean fclean re
