/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:41 by finoment          #+#    #+#             */
/*   Updated: 2026/02/11 15:59:49 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}
