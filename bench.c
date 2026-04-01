/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-27 12:38:25 by erakotom          #+#    #+#             */
/*   Updated: 2026-03-27 12:38:25 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    print_op(char *op, t_data *data)
{
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);

	data->bench.total_ops++;

	if(data->bench.bench_mode)
	{
		ft_putstr_fd("[bench] ", 2);
		ft_putstr_fd(op, 2);
		write(2, " : ", 4);
		ft_putnbr_fd(data->bench.total_ops, 2);
		write(2, "\n", 1);
	}
}