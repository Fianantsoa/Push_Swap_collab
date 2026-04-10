/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:21:32 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/10 14:15:47 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_data(int argc, char **argv, t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->bench.strategy = "Adaptive";
	data->stack_a = parsing(argc, argv, data);
	if (!data->stack_a)
		return (0);
	data->bench.disorder = ft_compute_disorder(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	if (!init_data(argc, argv, &data))
		return (1);
	ft_algo_selector(&data);
	if (data.bench.bench_mode)
		ft_print_bench(&data);
	ft_lstclear(&data.stack_a, free);
	return (0);
}
