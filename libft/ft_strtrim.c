/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:37:02 by finoment          #+#    #+#             */
/*   Updated: 2026/02/09 08:55:57 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_among(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	lens1;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	lens1 = ft_strlen(s1);
	start = 0;
	while (start < lens1)
	{
		if (!ft_is_among(s1[start], set))
			break ;
		start++;
	}
	end = lens1 - 1;
	while (end > start)
	{
		if (!ft_is_among(s1[end], set))
			break ;
		end--;
	}
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
