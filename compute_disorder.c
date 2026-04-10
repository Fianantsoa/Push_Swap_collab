/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:26:14 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/10 13:01:41 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_compute_disorder(t_data *data)
{
	t_list	*current;
	t_list	*compare;
	int		mistakes;
	int		total_pairs;

	if (!data->stack_a || ft_lstsize(data->stack_a) < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = data->stack_a;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			total_pairs++;
			if (*(int *)(current->content) > *(int *)(compare->content))
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (((float)mistakes / total_pairs) * 100);
}
