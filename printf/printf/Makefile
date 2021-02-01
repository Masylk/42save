# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 10:33:24 by mtogbe            #+#    #+#              #
#    Updated: 2021/01/22 16:07:56 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=printf

CC=gcc

CFLAGS=-Wall -Wextra

RM=rm -f

INC=ft_printf.h

SRC=../ft_atoi.c \
../ft_isdigit.c \
../ft_putchar_fd.c \
ft_printf.c setters.c ft_printf_utils.c

OBJ=$(SRC:.c=.o)


$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(SRC) $(INC) -o $(NAME)

all: $(NAME)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: clean fclean
