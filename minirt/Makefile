# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2021/02/21 12:34:45 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt

CC=gcc

CFLAGS=-Wall -Wextra -Werror

PATHS= obj/parsing obj/testing obj/managers

SRC=parsing/parse.c testing/test_utils.c testing/test_utils_lst.c \
	parsing/parse_struct.c parsing/parse_settings.c parsing/parse_shapes.c parsing/parse_utils.c \
	managers/window.c managers/hooks.c \
	main.c

RM=rm -rf

INC=-I.

OBJDIR = obj

OBJ=$(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I. -I/usr/local/include -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L /usr/local/lib -lmlx -Llib -lft -framework OpenGL -framework AppKit

$(OBJDIR) :
	mkdir $(OBJDIR) $(PATHS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJDIR)

re: fclean all

.PHONY: clean fclean
