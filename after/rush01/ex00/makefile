NAME := rush-01
SRCDIR := ./srcs
OBJDIR := ./srcs
INCDIR := -I ./includes
SRCS := $(wildcard $(SRCDIR)/*.c)
SRC := gen.cpp
SRC2 := gen_error.cpp
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
CC := gcc
CPP := g++
CFLAG := -Wall -Wextra -Werror
.PHONY: all clean fclean re delete test

all: rush-01 test

test : gen error

gen : $(SRC)
	$(CPP) -o $@ $^

error : $(SRC2)
	$(CPP) -o $@ $^

rush-01 : $(OBJS)
	$(CC) $(CFLAG) $(INCDIR) -o $@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAG) $(INCDIR) -c $< -o $@

delete:
	$(RM) $(NAME)
	$(RM) gen
	$(RM) error

clean:
	$(RM) $(OBJS)

fclean:	clean delete

re:	fclean all
