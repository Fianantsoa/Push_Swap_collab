/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:38:25 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/09 08:58:09 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_op(char *op, t_data *data)
{
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
	data->bench.total_ops++;
}

void	ft_putpercent(float n)
{
	long	total;

	total = (long)(n * 100 + 0.5);
	ft_putnbr_fd(total / 100, 2);
	write(2, ".", 1);
	if (total % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(total % 100, 2);
	write(2, "%", 2);
}

void	ft_print_bench(t_data *data)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putpercent(data->bench.disorder);
	write(2, "\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(data->bench.strategy, 2);
	write(2, " / ", 4);
	ft_putstr_fd(data->bench.algo, 2);
	write(2, "\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data->bench.total_ops, 2);
	write(2, "\n", 2);
	ft_print_bench_ops(data);
}

void	ft_print_bench_ops_verbose(t_data *data)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("ra: ", 2);
	ft_putnbr_fd(data->operations.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(data->operations.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(data->operations.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(data->operations.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(data->operations.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(data->operations.rrr, 2);
	write(2, "\n", 2);
}

void	ft_print_bench_ops(t_data *data)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(data->operations.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(data->operations.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(data->operations.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(data->operations.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(data->operations.pb, 2);
	write(2, "\n", 2);
	ft_print_bench_ops_verbose(data);
}
