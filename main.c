#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_list *tmp = stack;
	while (tmp)
	{
		printf("Valeur: %d | Adresse: %p\n", *(int *)tmp->content, tmp->content);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*stack;

	// Initialisation des stacks et bench
	data.stack_a = NULL;
	data.stack_b = NULL;
	data.bench.total_ops = 0;
	data.bench.bench_mode = 0;
	data.bench.strategy = 0;

	if (argc < 2)
	{
		printf("Usage: %s <numbers> [flags]\n", argv[0]);
		return (0);
	}

	// Parsing + validation
	stack = parsing(argc, argv, &data);
	if (!stack)
	{
		// parsing a échoué
		return (1);
	}
	data.stack_a = stack;

	printf("Stack construite:\n");
	print_stack(data.stack_a);

	// Ici tu pourrais appeler ton algo push_swap

	// Nettoyage mémoire
	ft_lstclear(&data.stack_a, free);

	return (0);
}