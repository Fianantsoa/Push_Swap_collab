/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:40:51 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/08 17:05:35 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = NULL;
	ft_lstadd_back(&data->stack_a, tmp);
	data->operations.ra++;
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
	ft_lstadd_back(&data->stack_b, tmp);
	data->operations.rb++;
	print_op("rb", data);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	data->operations.rr++;
	print_op("rr", data);
}
