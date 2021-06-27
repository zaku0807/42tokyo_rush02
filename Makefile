CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = rush-02

SRCS = file_read.c input.c main.c output.c rush.c split_num.c store.c

OBJS = $(SRCS:.c=.o)

$(NAME):$(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean all
