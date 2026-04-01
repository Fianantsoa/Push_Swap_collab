/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:18:57 by finoment          #+#    #+#             */
/*   Updated: 2026/02/09 08:53:55 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)(malloc(sizeof(t_list)));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
