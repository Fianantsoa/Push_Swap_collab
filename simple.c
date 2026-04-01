/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-25 13:54:17 by erakotom          #+#    #+#             */
/*   Updated: 2026-03-25 13:54:17 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_data *data)
{
	t_list	*tmp;
	int		min_val;
	int		min_pos;
	int		current_pos;

	if (!data->stack_a)
		return (-1);
	tmp = data->stack_a;
	min_val = *(int *)(tmp->content);
	min_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (*(int *)(tmp->content) < min_val)
		{
			min_val = *(int *)(tmp->content);
			min_pos = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return (min_pos);
}

static void	placement(t_data *data, int min_position)
{
	int	size;

	size = ft_lstsize(data->stack_a);
	if (min_position <= size / 2)
		while (min_position > 0)
		{
			ra(data);
			min_position--;
		}
	else
		while (min_position < size)
		{
			rra(data);
			min_position++;
		}
}

static void	simple_sort(t_data *data)
{
	int	a;
	int	b;
	int	c;

	if (ft_lstsize(data->stack_a) == 2 && *(int *)(data->stack_a->content) > 
		*(int *)(data->stack_a->next->content))
		return (sa(data));
	if (ft_lstsize(data->stack_a) < 3)
		return ;
	a = *(int *)data->stack_a->content;
	b = *(int *)data->stack_a->next->content;
	c = *(int *)data->stack_a->next->next->content;
	if (a > b && a > c)
		ra(data);
	else if (b > a && b > c)
		rra(data);
	a = *(int *)data->stack_a->content;
	b = *(int *)data->stack_a->next->content;
	if (a > b)
		sa(data);
}

void	ft_selection_sort(t_data *data)
{
	if (!data->stack_a)
		return ;
	while (ft_lstsize(data->stack_a) > 3)
	{
		placement(data, find_min_pos(data));
		pb(data);
	}
	simple_sort(data);
	while (data->stack_b)
	{
		pa(data);
	}
}