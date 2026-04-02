/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 07:45:15 by erakotom          #+#    #+#             */
/*   Updated: 2026/03/19 00:50:25 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"



typedef struct	bench
{
	float	disorder;
	char	*strategy;
	int	algorithm;
	int	total_ops;
	int	bench_mode;
	char	*algo;
}				s_bench;

typedef struct operations
{
	int	sa;
	int	sb;
	int	pa;
	int	pb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}				s_operation;

typedef struct	s_data 
{
	t_list	*stack_a;
	t_list	*stack_b;
	s_bench	bench;
	s_operation operations;
}				t_data;

void	sa(t_data *data);
void	sb(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);


t_list	*ft_tolist(char **str);
float	ft_compute_disorder(t_data *data);
void	ft_selection_sort(t_data *data);
t_list *parsing(int argc, char **argv, t_data *data);
void	print_op(char *op, t_data *data);
void	ft_print_bench(t_data *data);
void    ft_algo_selector(t_data *data);

#endif
