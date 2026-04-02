/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:21:32 by erakotom          #+#    #+#             */
/*   Updated: 2026/03/19 00:55:49 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>


void	print_stack(t_list *stack)
{
	t_list *tmp = stack;
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

	
	ft_selection_sort(&data);
	print_stack(data.stack_a);
	if (data.bench.bench_mode)
		ft_print_bench(&data);
	

	ft_lstclear(&data.stack_a, free);
	return (0);
}