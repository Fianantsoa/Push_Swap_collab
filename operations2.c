/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-07 14:48:29 by erakotom          #+#    #+#             */
/*   Updated: 2026-04-07 14:48:29 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_data *data)
{
	t_list	*first;
	t_list	*second;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	first = data->stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	data->stack_b = second;
	data->operations.sb++;
	print_op("sb", data);
}

void	pb(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_a)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = NULL;
	ft_lstadd_front(&data->stack_b, tmp);
	data->operations.pb++;
	print_op("pb", data);
}

void	rb(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_b ||!data->stack_b->next)
		return ;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	tmp->next = NULL;
	ft_lstadd_back(&data->stack_b, tmp);
	data->operations.rb++;
	print_op("rb", data);
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
