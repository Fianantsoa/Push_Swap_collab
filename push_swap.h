/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 07:45:15 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/10 14:26:18 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_chunk
{
	int	size;
	int	chunk_count;
	int	chunk_size;
	int	current_chunk;
	int	start;
	int	end;
	int	pushed;
	int	target;
	int	index;
}				t_chunk;

typedef struct bench
{
	float	disorder;
	char	*strategy;
	int		algorithm;
	int		total_ops;
	int		bench_mode;
	char	*algo;
}				t_bench;

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
}				t_operation;

typedef struct s_data
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_bench		bench;
	t_operation	operations;
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
void	selection_sort(t_data *data);
t_list	*parsing(int argc, char **argv, t_data *data);
int		is_valid_int(char *str);
int		has_duplicates(char **argv);
void	flag_search(char *argv, t_data *data);
char	*ft_strjoin_with_space(char *s1, char *s2);
void	print_op(char *op, t_data *data);
void	ft_print_bench(t_data *data);
void	ft_algo_selector(t_data *data);
void	reset_stack_a(t_data *data, int *arr, int size);
int		*index_stack(t_data *data);
void	radix_sort(t_data *data);
void	push_back_to_a(t_data *data);
void	push_chunks(t_data *data);
void	chunks_sort(t_data *data);
void	simple_sort(t_data *data);

#endif
