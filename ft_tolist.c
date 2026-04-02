/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:37:10 by erakotom          #+#    #+#             */
/*   Updated: 2026/03/18 23:13:09 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_tolist(char **str)
{
    t_list  *new_node;
	t_list	*head;
    int	*nb;
	int	i;

	i = 0;
	head = NULL;
	while (str[i])
	{
		nb = malloc(sizeof(int));
		if (!nb)
			return (NULL);
		*nb = ft_atoi(str[i]);
		new_node = ft_lstnew(nb);
		if (!new_node)
		{
			free(nb);
			ft_lstclear(&head, free);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		i++;
	}
    return (head);
}