/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:18 by finoment          #+#    #+#             */
/*   Updated: 2026/04/10 14:25:08 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_list *stack_b)
{
	t_list	*tmp;
	int		max;
	int		max_pos;
	int		i;
	int		value;

	if (!stack_b)
		return (0);
	tmp = stack_b;
	max = *(int *)tmp->content;
	max_pos = 0;
	i = 0;
	while (tmp)
	{
		value = *(int *)tmp->content;
		if (value > max)
		{
			max = value;
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_pos);
}

void	push_back_to_a(t_data *data)
{
	int	max_pos;
	int	moves;

	while (ft_lstsize(data->stack_b) > 0)
	{
		max_pos = find_max_pos(data->stack_b);
		if (max_pos <= ft_lstsize(data->stack_b) / 2)
		{
			while (max_pos-- > 0)
				rb(data);
		}
		else
		{
			moves = ft_lstsize(data->stack_b) - max_pos;
			while (moves-- > 0)
				rrb(data);
		}
		pa(data);
	}
}

void	chunks_sort(t_data *data)
{
	int	*array;

	if (ft_lstsize(data->stack_a) <= 5)
	{
		selection_sort(data);
		return ;
	}
	array = index_stack(data);
	push_chunks(data);
	push_back_to_a(data);
	reset_stack_a(data, array, ft_lstsize(data->stack_a));
	free(array);
}
