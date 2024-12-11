NAME	=	push_swap
BNAME	=	checker

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g

SRC		=	push_swap.c parse.c push.c swap.c rotate.c reverse.c stack.c utils.c \
			sort.c small_sorts.c target.c cost.c
OBJ		=	$(SRC:.c=.o)

BSRC	=	checker.c parse.c stack.c push.c swap.c rotate.c reverse.c utils.c \
			get_next_line.c get_next_line_utils.c
BOBJ	=	$(BSRC:.c=.o)

all		:	$(NAME)

bonus	:	$(BNAME)
	
$(NAME)	:	$(OBJ)
	$(CC) $^ -o $@

$(BNAME):	$(BOBJ)
	$(CC) $^ -o $@

%.o		:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ) $(BOBJ)

fclean	:	clean
	rm -f $(NAME) $(BNAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
