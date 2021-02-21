# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2021/02/20 14:16:13 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt

CC=gcc

CFLAGS=-Wall -Wextra

SRC=parse.c test_utils.c test_utils_lst.c \
	parse_struct.c parse_settings.c parse_shapes.c parse_utils.c \
	main.c

RM=rm -f

INC=-I.

OBJDIR = obj

OBJ=$(SRC:.c=$(OBJDIR)/.o)

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) -Wall -Wextra -Werror -I. -I/usr/local/include -c $< -o $@

$(NAME): $(OBJ)
	$(CC) *.o -L /usr/local/lib -lmlx -Llib -lft -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJDIR)

re: fclean all

.PHONY: clean fclean
