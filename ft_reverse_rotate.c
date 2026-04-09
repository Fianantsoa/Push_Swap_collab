/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:40:51 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/08 17:15:11 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	t_list	*before_last;
	t_list	*last;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	last = ft_lstlast(data->stack_a);
	before_last = data->stack_a;
	while (before_last->next != last)
	{
		before_last = before_last->next;
	}
	before_last->next = NULL;
	ft_lstadd_front(&data->stack_a, last);
	data->operations.rra++;
	print_op("rra", data);
}

void	rrb(t_data *data)
{
	t_list	*before_last;
	t_list	*last;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	last = ft_lstlast(data->stack_b);
	before_last = data->stack_b;
	while (before_last->next != last)
	{
		before_last = before_last->next;
	}
	before_last->next = NULL;
	ft_lstadd_front(&data->stack_b, last);
	data->operations.rrb++;
	print_op("rrb", data);
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	data->operations.rrr++;
	print_op("rrr", data);
}
