/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:37:10 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/01 17:50:16 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_tolist(char **str)
{
	t_list	*new_node;
	t_list	*head;
	int		*nb;
	int		i;

	i = 1;
	head = NULL;
	while (str[i])
	{
		nb = malloc(sizeof(int));
		if (!nb)
			return (ft_lstclear(&head, free), NULL);
		*nb = ft_atoi(str[i]);

		new_node = ft_lstnew(nb);
		if (!new_node)
		{
			free(nb);
			return (ft_lstclear(&head, free), NULL);
		}
		ft_lstadd_back(&head, new_node);
		i++;
	}
	return (head);
}
