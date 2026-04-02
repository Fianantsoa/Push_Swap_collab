NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = main.c ft_tolist.c validation.c compute_disorder.c simple.c bench.c ft_swap.c algo_selector.c
OBJ = $(SRC:.c=.o)

LIBFT = libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re