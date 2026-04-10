NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c parsing.c parsing_utils.c parsing_utils2.c compute_disorder.c simple.c printing.c \
      ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c algo_selector.c index_stack.c \
      complex.c medium.c medium_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re