NAME = rush-02
SRCS = main.c base.c check.c keyword.c put_num.c tostring.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAG = -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
re:
	rm -f $(OBJS)
	rm -f $(NAME)
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
