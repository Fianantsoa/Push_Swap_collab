/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:19:57 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/10 14:23:34 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_data *data)
{
	int	i;
	int	size;
	int	max_bits;
	int	j;
	int	val;

	i = 0;
	size = ft_lstsize(data->stack_a);
	max_bits = get_max_bits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			val = *(int *)data->stack_a->content;
			if (((val >> i) & 1) == 1)
				ra(data);
			else
				pb(data);
		}
		while (data->stack_b)
			pa(data);
		i++;
	}
}
