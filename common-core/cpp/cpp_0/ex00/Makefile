# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2021/07/07 04:47:46 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=megaphone

CC=g++

OBJDIR = obj

CFLAGS=-Wall -Wextra -Werror

PATHS= $(OBJDIR)/srcs

SRC=megaphone.cpp

INCFLAGS=-I.

RM=rm -rf

INC=-I.

OBJ=$(SRC:%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR) :
	mkdir $(OBJDIR) $(PATHS)

all: $(NAME)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME) $(OBJDIR)

re: fclean all

.PHONY: clean fclean
