# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 10:33:24 by mtogbe            #+#    #+#              #
#    Updated: 2021/01/22 10:33:27 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

INC=libft.h

SRC=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
ft_memmove.c ft_memchr.c ft_memcmp.c \
ft_strlen.c ft_strdup.c ft_calloc.c \
ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
ft_strncmp.c ft_atoi.c ft_itoa.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BON=ft_lstnew.c ft_lstadd_front.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_isupper_bonus.c ft_islower_bonus.c \
ft_isspace_bonus.c ft_isgraph_bonus.c ft_iscntrl_bonus.c ft_ispunct_bonus.c ft_isxdigit_bonus.c

OBJ=$(SRC:.c=.o)

BONUS_OBJ= $(BON:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(INC)

$(NAME): $(OBJ)
	ar rcs	$(NAME)	$(OBJ)

all: $(NAME)

bonus:
	@make	all	OBJ="$(OBJ) $(BONUS_OBJ)"

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: clean fclean
