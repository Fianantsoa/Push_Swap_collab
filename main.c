/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:21:32 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/09 06:30:43 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("Valeur: %d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
}

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->bench.strategy = "Adaptive";
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	init_data(&data);
	data.stack_a = parsing(argc, argv, &data);
	if (!data.stack_a)
		return (1);
	data.bench.disorder = ft_compute_disorder(&data);
	ft_algo_selector(&data);
	print_stack(data.stack_a);
	if (data.bench.bench_mode)
		ft_print_bench(&data);
	ft_lstclear(&data.stack_a, free);
	return (0);
}
