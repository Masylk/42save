NAME=test

CC=c++

OBJDIR = obj

CFLAGS=-Wall -Wextra -Werror

PATHS= $(OBJDIR)/srcs

SRC=Weapon.cpp HumanA.cpp HumanB.cpp main.cpp

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
