/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 07:45:15 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/01 15:25:42 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#ifndef STRATEGY
#define STRATEGY = 1;
#endif
#include "libft.h"

typedef struct	s_data 
{
	t_list	*stack_a;
	t_list	*stack_b;
	s_bench	bench;
}				t_data;

typedef struct	bench
{
	float	disorder;
	int	strategy;
	int	total_ops;
	int	bench_mode;
}				s_bench;

t_list	*ft_tolist(char **str);
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
float	ft_compute_disorder(t_data *data);
void	ft_selection_sort(t_data *data);


void	print_op(char *op, t_data *data);
#endif
