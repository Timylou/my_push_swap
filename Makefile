NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g

SRC		=	push_swap.c parse.c push.c swap.c rotate.c reverse.c stack.c utils.c \
			sort.c small_sorts.c target.c
OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $^ -o $@

$(OBJ)	:	$(SRC)
	$(CC) $(CFLAGS) -c $^

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
