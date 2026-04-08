NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = main.c parsing.c parsing_utils.c parsing_utils2.c compute_disorder.c simple.c printing.c operations.c operations2.c operations3.c algo_selector.c index_stack.c complex.c medium.c medium_utils.c
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
# 	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make clean

re: fclean all

.PHONY: all clean fclean re