/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:59:45 by finoment          #+#    #+#             */
/*   Updated: 2026/02/09 08:55:46 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_find(char *text, char *find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (text[i] == find[j])
	{
		i++;
		j++;
		if (find[j] == '\0')
		{
			return (1);
		}
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*ptr;

	ptr = NULL;
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (ft_is_find((char *) &big[i], (char *) little)
			&& (i + ft_strlen(little)) <= len)
		{
			ptr = (char *) &big[i];
			break ;
		}
		i++;
	}
	if (little[0] == '\0')
	{
		return ((char *) big);
	}
	return (ptr);
}
