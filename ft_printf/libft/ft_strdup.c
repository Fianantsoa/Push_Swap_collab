/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:46:59 by finoment          #+#    #+#             */
/*   Updated: 2026/02/11 09:06:42 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		lens;
	char	*dup;

	lens = 0;
	while (s[lens] != 0)
		lens++;
	dup = (char *) malloc(sizeof(char) * (lens + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < lens)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
