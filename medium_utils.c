/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:18 by finoment          #+#    #+#             */
/*   Updated: 2026/04/08 16:05:04 by finoment         ###   ########.fr       */
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

static void	init_chunk(t_chunk *c, t_data *data)
{
	c->size = ft_lstsize(data->stack_a);
	if (c->size <= 100)
		c->chunk_count = 5;
	else
		c->chunk_count = 11;
	c->chunk_size = c->size / c->chunk_count;
	c->current_chunk = 0;
	c->start = 0;
	c->end = c->chunk_size - 1;
	c->pushed = 0;
	c->target = c->chunk_size;
	c->index = 0;
}

static void	process_chunk_step(t_data *data, t_chunk *chunk)
{
	chunk->index = *(int *)data->stack_a->content;
	if (chunk->index >= chunk->start && chunk->index <= chunk->end)
	{
		pb(data);
		chunk->pushed++;
		if (chunk->index < chunk->start + (chunk->chunk_size / 2))
			rb(data);
	}
	else
		ra(data);
	if (chunk->pushed == chunk->target)
	{
		chunk->current_chunk++;
		chunk->start = chunk->current_chunk * chunk->chunk_size;
		chunk->end = chunk->start + chunk->chunk_size - 1;
		if (chunk->end >= chunk->size)
			chunk->end = chunk->size - 1;
		chunk->target = chunk->end - chunk->start + 1;
		chunk->pushed = 0;
	}
}

void	push_chunks(t_data *data)
{
	t_chunk	chunk;

	init_chunk(&chunk, data);
	while (ft_lstsize(data->stack_a) > 0)
		process_chunk_step(data, &chunk);
}
