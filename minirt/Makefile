# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2021/03/22 18:05:34 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=miniRT

CC=gcc

OBJDIR = obj

CFLAGS=-Wall -Wextra -Werror

PATHS= $(OBJDIR)/parsing $(OBJDIR)/testing $(OBJDIR)/managers $(OBJDIR)/rendering $(OBJDIR)/maths

SRC=parsing/parse.c parsing/add_camera.c parsing/limit.c \
	parsing/parse_struct.c parsing/parse_settings.c parsing/parse_shapes.c parsing/parse_utils.c \
	managers/window.c managers/hooks.c managers/camera.c managers/altcameras.c \
	rendering/renderer.c rendering/sphere.c rendering/square.c rendering/triangle.c \
	rendering/plane.c rendering/cylinder.c rendering/cylinder_next.c \
	rendering/shadows.c rendering/save.c \
	maths/vec_op.c maths/math_utils.c maths/mathv.c \
	main.c

INCFLAGS=-I.

LFLAGS= -Llib -lft


ENV:= $(shell uname -s)

ifeq ($(ENV), Linux)
	INCFLAGS += -I/usr/include -I./lib/mlx_linux
	LFLAGS = -Llibft -lft -L./lib/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
endif
ifeq ($(ENV), Darwin)
	INCFLAGS += -I/usr/local/include
	LFLAGS = -Llibft -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
endif

RM=rm -rf

INC=-I.

OBJ=$(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C libft
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
