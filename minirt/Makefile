# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2021/02/22 14:42:29 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt

CC=gcc

OBJDIR = obj

CFLAGS=-Wall -Wextra -Werror

PATHS= $(OBJDIR)/parsing $(OBJDIR)/testing $(OBJDIR)/managers $(OBJDIR)/rendering

SRC=parsing/parse.c testing/test_utils.c testing/test_utils_lst.c \
	parsing/parse_struct.c parsing/parse_settings.c parsing/parse_shapes.c parsing/parse_utils.c \
	managers/window.c managers/hooks.c \
	rendering/renderer.c \
	tests.c main.c

INCFLAGS=-I.

LFLAGS=-Llib -lft

ENV:= $(shell uname -s)

ifeq ($(ENV), Linux)
	INCFLAGS += -I/usr/include -I./lib/mlx_linux -O3
	LFLAGS += -L./lib/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
endif
ifeq ($(ENV), Darwin)
	INCFLAGS += -I/usr/local/include
	LFLAGS = -L/usr/local/lib -lmlx -framework OpenGL -framework -AppKit
endif

RM=rm -rf

INC=-I.

OBJ=$(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(OBJDIR) :
	mkdir $(OBJDIR) $(PATHS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJDIR)

re: fclean all

.PHONY: clean fclean
