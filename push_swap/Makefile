# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2021/04/01 16:31:04 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=gcc

OBJDIR = obj

CFLAGS=-Wall -Wextra -Werror

PATHS= $(OBJDIR)/srcs

SRC=push_swap.c \
	srcs/check_args.c srcs/op_a.c srcs/op_b.c srcs/op_c.c srcs/op_d.c \
	srcs/utils.c srcs/setup.c srcs/init.c srcs/is_sorted.c srcs/rd_sort.c \
	srcs/boxes.c srcs/exit.c srcs/small_sort.c srcs/choose_sort.c

INCFLAGS=-I.

LFLAGS= -Llib -lft

RM=rm -rf

INC=-I.

OBJ=$(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $@ $^ -Llibft/ -lft

$(OBJDIR) :
	mkdir $(OBJDIR) $(PATHS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJDIR)

re: fclean all

.PHONY: clean fclean
