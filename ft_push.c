/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:40:51 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/08 17:14:24 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_b)
		return ;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	tmp->next = NULL;
	ft_lstadd_front(&data->stack_a, tmp);
	data->operations.pa++;
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
	ft_lstadd_front(&data->stack_b, tmp);
	data->operations.pb++;
	print_op("pb", data);
}
