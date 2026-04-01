/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:25:54 by finoment          #+#    #+#             */
/*   Updated: 2026/03/18 11:37:39 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_ltoh(unsigned long n)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	div;
	long	temp;

	len = ft_intlen(n);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp = n;
		div = len - i - 1;
		while (div--)
			temp /= 16;
		if (temp % 16 >= 0 && temp % 16 <= 10)
			str[i] = (temp % 16) + '0';
		if (temp % 16 >= 10 && temp % 16 <= 15)
			str[i] = 'a' + ((temp % 16) - 10);
		i++;
	}
	str[len] = '\0';
	return (str);
}

int	ft_n_show_c(long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (base == 10 && n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((n % 10 + '0'), fd);
}

char	*ft_strupcase(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
