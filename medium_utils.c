/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:18 by finoment          #+#    #+#             */
/*   Updated: 2026/04/10 09:54:39 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

static void	init_chunk(t_chunk *c, t_data *data)
{
	c->size = ft_lstsize(data->stack_a);
	c->chunk_count = ft_sqrt(ft_lstsize(data->stack_a) - 1);
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
