NAME := $(wildcard rush0*)
SRCDIR := ./srcs
OBJDIR := ./srcs
INCDIR := -I ./includes
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
CC := gcc
CFLAG := -Wall -Wextra -Werror
.PHONY: all clean fclean re delete test build

all: test

build : $(OBJS) rush00 rush01 rush02 rush03 rush04

rush00 : $(OBJS)
	$(CC) $(CFLAG) $(INCDIR) -o $@ \
	$(SRCDIR)/ft_putchar.o \
	$(SRCDIR)/main.o \
	$(SRCDIR)/rush00.o

rush01 : $(OBJS)
	$(CC) $(CFLAG) $(INCDIR) -o $@ \
	$(SRCDIR)/ft_putchar.o \
	$(SRCDIR)/main.o \
	$(SRCDIR)/rush01.o

rush02 : $(OBJS)
	$(CC) $(CFLAG) $(INCDIR) -o $@ \
	$(SRCDIR)/ft_putchar.o \
	$(SRCDIR)/main.o \
	$(SRCDIR)/rush02.o

rush03 : $(OBJS)
	$(CC) $(CFLAG) $(INCDIR) -o $@ \
	$(SRCDIR)/ft_putchar.o \
	$(SRCDIR)/main.o \
	$(SRCDIR)/rush03.o

rush04 : $(OBJS)
	$(CC) $(CFLAG) $(INCDIR) -o $@ \
	$(SRCDIR)/ft_putchar.o \
	$(SRCDIR)/main.o \
	$(SRCDIR)/rush04.o

$(SRCDIR)/%.o : $(OBJDIR)/%.c
	$(CC) $(CFLAG) $(INCDIR) -c $< -o $@

delete:
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean delete

re:	fclean all

test:
	./script/test.sh > ./output/sample.txt 2>&1
