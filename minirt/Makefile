# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2021/02/17 15:14:21 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt

CC=gcc

CFLAGS=-Wall -Wextra

SRC=parse.c \
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
