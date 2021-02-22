# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 10:33:24 by mtogbe            #+#    #+#              #
#    Updated: 2021/02/03 15:35:35 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=printf

CC=gcc

CFLAGS=-Wall -Wextra

RM=rm -f

INC=-I./ft_printf.h

SRC=../ft_atoi.c ../ft_itoa.c ../ft_utoa.c \
../ft_itoa_base.c ../ft_utoa_base.c ../ft_ultoa_base.c \
../ft_strlen.c ../ft_strlcpy.c ../ft_strlcat.c ../ft_strjoin.c \
../ft_isdigit.c ../ft_calloc.c ../ft_bzero.c \
../ft_putchar_fd.c \
conv_utils.c conv_s.c conv_c.c conv_d.c conv_x.c conv_u.c conv_p.c \
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
