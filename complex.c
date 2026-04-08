/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-07 18:19:57 by erakotom          #+#    #+#             */
/*   Updated: 2026-04-07 18:19:57 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	// On décale le nombre vers la droite jusqu'à ce qu'il soit égal à 0
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void radix_sort(t_data *data)
{
    int i = 0;
    int size = ft_lstsize(data->stack_a);
    int max_bits = get_max_bits(size); // Combien de bits pour écrire "size" ?

    while (i < max_bits)
    {
        int j = 0;
        while (j++ < size)
        {
            int val = *(int *)data->stack_a->content;
            if (((val >> i) & 1) == 1)
                ra(data);
            else
                pb(data);
        }
        while (data->stack_b)
            pa(data);
        i++;
    }
}