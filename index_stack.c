/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 09:57:12 by finoment          #+#    #+#             */
/*   Updated: 2026/04/08 17:13:30 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_stack_to_tab_int(t_list *stack, int size)
{
	t_list	*tmp;
	int		i;
	int		*arr;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (arr);
}

static void	ft_sorted_arr(int *arr, int size)
{
	int	max;
	int	i;

	while (size)
	{
		i = 0;
		max = arr[size - 1];
		while (i < size - 1)
		{
			if (arr[i] > max)
			{
				arr[size - 1] = arr[i];
				arr[i] = max;
				max = arr[size - 1];
			}
			i++;
		}
		size--;
	}
}

void	index_stack(t_data *data)
{
	t_list	*tmp;
	int		size;
	int		*arr;
	int		i;

	size = ft_lstsize(data->stack_a);
	arr = ft_stack_to_tab_int(data->stack_a, size);
	ft_sorted_arr(arr, size);
	tmp = data->stack_a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)tmp->content == arr[i])
			{
				*(int *)tmp->content = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}
