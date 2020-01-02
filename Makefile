# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 06:10:18 by kdumarai          #+#    #+#              #
#    Updated: 2020/01/02 21:44:22 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
TESTNAME = testsuite

SRCDIR = srcs
SRCFILES = ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_strdup.s \
			ft_write.s \
			ft_read.s
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

OBJDIR = objs/lib
OBJS = $(SRCS:$(SRCDIR)/%.s=$(OBJDIR)/%.o)

TESTSRCDIR = tests
TESTSRCFILES = main.c
TESTSRCS = $(addprefix $(TESTSRCDIR)/, $(TESTSRCFILES))

TESTOBJDIR = objs/tests
TESTOBJS = $(TESTSRCS:$(TESTSRCDIR)/%.c=$(TESTOBJDIR)/%.o)

TESTINCDIR = includes
TESTINCFILES = libasm.h
TESTINCS = $(addprefix $(TESTINCDIR)/, $(TESTINCFILES))

PROJTEXT = \033[1;36m$(basename $(NAME)): \033[0;39m

all: $(NAME)

test: $(TESTNAME)

$(NAME): $(OBJS)
	@ printf "$(PROJTEXT)Linking\n"
	@ ar rcs $@ $(OBJS)
	@ printf "$(PROJTEXT)\033[1;32mLib built at $@\033[0;39m\n"

$(TESTNAME): $(NAME) $(TESTOBJS) $(TESTINCS)
	@ printf "$(PROJTEXT)Linking\n"
	@ gcc -L. -lasm -o $@ $(TESTOBJS)
	@ printf "$(PROJTEXT)\033[1;32mTests built at $@\033[0;39m\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@ if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	@ printf "\033[K$(PROJTEXT)Compiling ASM code\033[1;33m $<\033[0;39m\n"
	@ nasm -f macho64 $< -o $@

$(TESTOBJDIR)/%.o: $(TESTSRCDIR)/%.c
	@ if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	@ printf "\033[K$(PROJTEXT)Compiling C code\033[1;33m $<\033[0;39m\n"
	@ gcc -I$(TESTINCDIR) -I. -c $< -o $@

clean:
	@ rm -rf $(dir $(OBJDIR))
	@ printf "$(PROJTEXT)Removed objects\n"

fclean: clean
	@ rm -f $(NAME) $(TESTNAME)
	@ printf "$(PROJTEXT)Removed $(NAME) and $(TESTNAME)\n"

re: fclean all

.PHONY: all clean fclean re
