/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:40:51 by erakotom          #+#    #+#             */
/*   Updated: 2026/03/19 10:39:06 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	t_list	*first;
	t_list	*second;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	first = data->stack_a;
	second = first->next;

	first->next = second->next;
	second->next = first;
	data->stack_a = second;
	print_op("sa", data);
}

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
	print_op("sb", data);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	print_op("ss", data);
}

void	pa(t_data *data)
{	
	t_list	*tmp;

	if (!data->stack_b)
		return ;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	tmp->next = NULL;
	ft_lstadd_front(data->stack_a, tmp);
	print_op("pa", data);
}

void	pb(t_data *data)
{	
	t_list	*tmp;

	if (!data->stack_a)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = NULL;
	ft_lstadd_front(data->stack_b, tmp);
	print_op("pb", data);
}

void	ra(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = NULL;
	ft_lstadd_back(data->stack_a, tmp);
	print_op("ra", data);
}

void	rb(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_b ||!data->stack_b->next)
		return ;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	tmp->next = NULL;
	ft_lstadd_back(data->stack_b, tmp);
	print_op("rb", data);
}

void	rr(t_data *data)
{
	ra(data->stack_a);
	rb(data->stack_b);
	print_op("rr", data);
}

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

	ft_lstadd_front(data->stack_a, last);
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

	ft_lstadd_front(data->stack_b, last);
	print_op("rrb", data);
}
void	rrr(t_data *data)
{
	rra(data->stack_a);
	rrb(data->stack_b);
	print_op("rrr", data);
}

