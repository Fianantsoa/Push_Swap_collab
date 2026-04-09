/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:10:44 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/08 17:28:15 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_search(char *argv, t_data *data)
{
	if (ft_strnstr(argv, "--bench", ft_strlen(argv)) != NULL)
	{
		data->bench.bench_mode = 1;
		ft_memset(ft_strnstr(argv, "--bench", ft_strlen(argv)), ' ', 7);
	}
	if (ft_strnstr(argv, "--simple", ft_strlen(argv)) != NULL)
	{
		data->bench.strategy = "Simple";
		ft_memset(ft_strnstr(argv, "--simple", ft_strlen(argv)), ' ', 8);
	}
	if (ft_strnstr(argv, "--medium", ft_strlen(argv)) != NULL)
	{
		data->bench.strategy = "Medium";
		ft_memset(ft_strnstr(argv, "--medium", ft_strlen(argv)), ' ', 8);
	}
	if (ft_strnstr(argv, "--complex", ft_strlen(argv)) != NULL)
	{
		data->bench.strategy = "Complex";
		ft_memset(ft_strnstr(argv, "--complex", ft_strlen(argv)), ' ', 9);
	}
	if (ft_strnstr(argv, "--adaptive", ft_strlen(argv)) != NULL)
	{
		data->bench.strategy = "Adaptive";
		ft_memset(ft_strnstr(argv, "--adaptive", ft_strlen(argv)), ' ', 10);
	}
}

char	*join_args(int argc, char **argv, t_data *data)
{
	char	*str_arg;
	int		i;

	str_arg = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		flag_search(argv[i], data);
		str_arg = ft_strjoin_with_space(str_arg, argv[i]);
		i++;
	}
	return (str_arg);
}

long	ft_atol(char *str)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
	}
	return (sign * result);
}

int	has_duplicates(char **argv)
{
	int		i;
	int		j;
	long	value_i;

	i = 0;
	while (argv[i])
	{
		value_i = ft_atol(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (value_i == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
}
