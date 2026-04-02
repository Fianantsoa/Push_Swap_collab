/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-30 13:10:44 by erakotom          #+#    #+#             */
/*   Updated: 2026-03-30 13:10:44 by erakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


long	ft_atol(char *str)
{
	long	result;
	int	i;
	int	sign;

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

static int	is_digit_str(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_int(char *str)
{
	long long	res;
	int			i;
	int			sign;

	if (!is_digit_str(str))
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			return (0);
	}
	return (1);
}

int	is_valid(char **argv)
{
	int	i;

	i =0;
	while (argv[i])
	{
		if (!is_valid_int(argv[i]))
			return(0);
		i++;
	}
	if (has_duplicates(argv))
		return(0);
	return (1);
}

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

char *ft_strjoin_with_space(char *s1, char *s2)
{
    char *tmp;
    char *result;

    tmp = ft_strjoin(s1, s2);
    free(s1);
    result = ft_strjoin(tmp, " ");
    free(tmp);
    return (result);
}

static char	*join_args(int argc, char **argv, t_data *data)
{
	char    *str_arg;
    int     i;

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

t_list *parsing(int argc, char **argv, t_data *data)
{
	char	*str_arg;
	char	**new_arg;
	t_list	*stack_a;
	
	str_arg = join_args(argc, argv, data);
	if (!str_arg)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	new_arg = ft_split(str_arg, ' ');
	free(str_arg);
	if (!new_arg)
		return (NULL);
	if (is_valid(new_arg))
	{
		stack_a = ft_tolist(new_arg);
		free_tab(new_arg);
		return (stack_a);
	}
	free_tab(new_arg);
	write (2, "Error\n", 7);
	return(NULL);
}
