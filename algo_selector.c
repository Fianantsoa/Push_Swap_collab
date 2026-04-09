/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:50:04 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/09 08:43:23 by finoment         ###   ########.fr       */
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
	ft_algo_seter(data);
	if (data->bench.algorithm == 1)
	{
		ft_selection_sort(data);
	}
	else if (data->bench.algorithm == 2)
	{
		medium(data);
	}
	else if (data->bench.algorithm == 3)
	{
		radix_sort(data);
	}
}
