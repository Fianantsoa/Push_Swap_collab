/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-23 13:26:14 by erakotom          #+#    #+#             */
/*   Updated: 2026-03-23 13:26:14 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float   ft_compute_disorder(t_data *data)
{
	t_list	*tmp;
	int	mistakes;
	int pairs;

	if (!data->stack_a || !data->stack_a->next)
		return (0.0);
	mistakes = 0;
	pairs = ft_lstsize(data->stack_a) - 1;
	tmp = data->stack_a;
	while(tmp->next != NULL)
	{
		if (*(int *)(tmp->content) > *(int *)(tmp->next)->content)
			mistakes++;;
		tmp = tmp->next;
	}
	return (((float)mistakes / pairs) * 100);
}