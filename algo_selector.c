/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:50:04 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/10 14:24:24 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive_selector(t_data *data)
{
	if (data->bench.disorder < 20)
	{
		data->bench.algorithm = 1;
		data->bench.algo = "O(n²)";
	}
	else if (data->bench.disorder >= 20 && data->bench.disorder < 50)
	{
		data->bench.algorithm = 2;
		data->bench.algo = "O(n√n)";
	}
	else if (data->bench.disorder >= 50)
	{
		data->bench.algorithm = 3;
		data->bench.algo = "O(n log n)";
	}
}

void	ft_algo_seter(t_data *data)
{
	if (ft_strncmp(data->bench.strategy, "Simple", 7) == 0)
	{
		data->bench.algorithm = 1;
		data->bench.algo = "O(n²)";
	}
	else if (ft_strncmp(data->bench.strategy, "Medium", 7) == 0)
	{
		data->bench.algorithm = 2;
		data->bench.algo = "O(n√n)";
	}
	else if (ft_strncmp(data->bench.strategy, "Complex", 8) == 0)
	{
		data->bench.algorithm = 3;
		data->bench.algo = "O(n log n)";
	}
	else
	{
		ft_adaptive_selector(data);
	}
}

void	ft_algo_selector(t_data *data)
{
	int	*array;

	ft_algo_seter(data);
	if (data->bench.algorithm == 1)
	{
		selection_sort(data);
	}
	else if (data->bench.algorithm == 2)
	{
		chunks_sort(data);
	}
	else if (data->bench.algorithm == 3)
	{
		array = index_stack(data);
		if (ft_lstsize(data->stack_a) <= 5)
		{
			selection_sort(data);
			return ;
		}
		radix_sort(data);
		reset_stack_a(data, array, ft_lstsize(data->stack_a));
		free(array);
	}
}
