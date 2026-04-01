NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = main.c bench.c compute_disorder.c ft_swap.c ft_tolist.c simple.c validation.c
OBJ = $(SRC:.c=.o)

LIBFTPRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(LIBFTPRINTF):
	make -C ft_printf

$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(FLAGS) $(OBJ) $(LIBFTPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re