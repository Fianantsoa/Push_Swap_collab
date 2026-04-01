/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:01:03 by finoment          #+#    #+#             */
/*   Updated: 2026/03/18 11:55:31 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_print_len(const char c, va_list args)
{
	char	*str;

	if (c == 'c')
		return (va_arg(args, int), 1);
	if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			return (6);
		return (ft_strlen(str));
	}
	if (c == 'd' || c == 'i')
		return (ft_n_show_c(va_arg(args, int), 10));
	if (c == 'u')
		return (ft_n_show_c(va_arg(args, unsigned int), 10));
	if (c == 'x' || c == 'X')
		return (ft_n_show_c(va_arg(args, unsigned int), 16));
	if (c == 'p')
		return (ft_n_show_c(va_arg(args, unsigned long), 16) + 2);
	if (c == '%')
		return (1);
	return (0);
}

static char	*ft_flag_pointer(va_list args)
{
	unsigned long	pointer;

	pointer = (unsigned long) va_arg(args, void *);
	if (pointer == 0)
		return (NULL);
	else
		return (ft_ltoh(pointer));
}

static void	ft_print_hex(char type, va_list args, size_t *count)
{
	char	*str;

	if (type == 'p')
	{
		str = ft_flag_pointer(args);
		if (str)
			ft_putstr_fd("0x", 1);
		*count += 2;
	}
	if (type == 'x' || type == 'X')
		str = ft_ltoh(va_arg(args, unsigned int));
	if (type == 'X')
		str = ft_strupcase(str);
	if (!str)
	{
		ft_putstr_fd("(nil)", 1);
		*count += 2;
	}
	else
	{
		ft_putstr_fd(str, 1);
		*count += ft_strlen(str) - 1;
	}
	free(str);
}

static void	ft_print_arg(char type, va_list args, size_t *count)
{
	va_list	copy;
	char	*str;

	va_copy(copy, args);
	if (ft_strchr("csdiu%%", type))
		*count += ft_get_print_len(type, copy) - 1;
	va_end(copy);
	if (type == 'c')
		ft_putchar_fd((int) va_arg(args, int), 1);
	if (type == 'd' || type == 'i')
		ft_putnbr_fd((int) va_arg(args, int), 1);
	if (type == 's')
	{
		str = (char *) va_arg(args, char *);
		if (str)
			ft_putstr_fd(str, 1);
		else
			ft_putstr_fd("(null)", 1);
	}
	if (type == '%')
		ft_putchar_fd('%', 1);
	if (type == 'u')
		ft_putunbr_fd(((unsigned int) va_arg(args, unsigned int)), 1);
	if (type == 'p' || type == 'x' || type == 'X')
		ft_print_hex(type, args, count);
}

// static void	ft_print_and_count(char chr, size_t *count)
// {
// 	ft_putchar_fd(chr, 1);
// 	*count += 1;
// }

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format != '\0' && ++count != 0)
	{
		if (*format != '%')
			ft_putchar_fd(*format, 1);
		else
		{
			if (ft_strchr("csdiupxX%%", *format++))
				ft_print_arg(*format, args, &count);
			if (!ft_strchr("csdiupxX%%", *format))
			{
				ft_putchar_fd('%', 1);
				ft_putchar_fd(*format, 1);
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
