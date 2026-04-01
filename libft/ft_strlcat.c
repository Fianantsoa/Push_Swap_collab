/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:35:06 by finoment          #+#    #+#             */
/*   Updated: 2026/02/09 08:55:20 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_dest = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size == 0 || len_dest > size)
		return (size + len_src);
	i = 0;
	while (i + len_dest < size - 1 && src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	if (size != 1)
		dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
