/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:04:08 by finoment          #+#    #+#             */
/*   Updated: 2026/03/17 17:10:43 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_putunbr_fd(unsigned int n, int fd);
char	*ft_ltoh(unsigned long n);
char	*ft_strupcase(char *s);
int		ft_n_show_c(long n, int base);

#endif