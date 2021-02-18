# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2021/02/18 16:35:59 by mtogbe           ###   ########.fr        #
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

OBJ=$(SRC:.c=.o)

BONUS_OBJ= $(BON:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I /usr/local/include -c $< -o $@

$(NAME): $(OBJ)
	$(CC) *.o -L /usr/local/lib -lmlx -Llib -lft -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

bonus:
	@make	all	OBJ="$(OBJ) $(BONUS_OBJ)"

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean