/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:51:15 by finoment          #+#    #+#             */
/*   Updated: 2026/02/11 15:40:11 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespaces(char chr)
{
	char	*ignore_chr;
	int		j;

	ignore_chr = " \t\n\v\f\r";
	j = 0;
	while (j <= 6)
	{
		if (chr == ignore_chr[j])
			return (1);
		j++;
	}
	return (0);
}

static int	ft_manage_sign(char c)
{
	if (c == 45)
		return (-1);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	i = 0;
	if (nptr[0] == '\0')
		return (0);
	while (ft_is_whitespaces(nptr[i]))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		sign = ft_manage_sign(nptr[i]);
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + (int)(nptr[i] - 48);
		i++;
	}
	return (sign * num);
}
