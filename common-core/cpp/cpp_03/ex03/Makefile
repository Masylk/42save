# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2022/05/08 15:47:06 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=test

CC=c++

OBJDIR = obj

CFLAGS=-Wall -Wextra -Werror -std=c++98

PATHS= $(OBJDIR)/srcs

SRC=main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

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
