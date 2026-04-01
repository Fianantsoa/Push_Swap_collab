/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:32:40 by finoment          #+#    #+#             */
/*   Updated: 2026/02/11 16:12:47 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	dest_tmp = (unsigned char *) dest;
	src_tmp = (unsigned char *) src;
	i = 0;
	if (dest_tmp > src_tmp)
	{
		while (n--)
			dest_tmp[n] = src_tmp[n];
	}
	else
	{
		while (n--)
		{
			dest_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dest_tmp);
}
