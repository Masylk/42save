# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:23:31 by mtogbe            #+#    #+#              #
#    Updated: 2021/12/01 17:23:10 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=test

CC=clang++

OBJDIR = obj

CFLAGS=-Wall -Wextra -Werror --std=c++98

PATHS= $(OBJDIR)/srcs $(OBJDIR)/tester

SRC=main.cpp

INCFLAGS=-I. -I./utils -I./containers -I./iterators -I./tester -I./containers_test -I./containers_test/srcs/map -I./containers_test/srcs

RM=rm -rf

INC=-I.

OBJ=$(SRC:%.cpp=$(OBJDIR)/%.o)

deps	:= $(patsubst %.o,%.d,$(OBJ))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< $(DEPFLAGS) -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR) :
	mkdir $(OBJDIR) $(PATHS)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(deps)
fclean: clean
	$(RM) $(NAME) $(OBJDIR)

re: fclean all

.PHONY: clean fclean
