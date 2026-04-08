/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-07 14:50:48 by erakotom          #+#    #+#             */
/*   Updated: 2026-04-07 14:50:48 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	data->operations.ss++;
	print_op("ss", data);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	data->operations.rr++;
	print_op("rr", data);
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	data->operations.rrr++;
	print_op("rrr", data);
}
