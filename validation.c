/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:10:44 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/01 15:20:33 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	is_valid(char *argv)
{
	if (is_num(argv))
	{
		if(is_integer_limits(argv));

	}
	return (0);
}
int	ft_atol(char *argv)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32)
		i++;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		result = result * 10 + (argv[i] - '0');
		i++;
	}
	result = result * sign;
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return (1);
}

int is_integer_limits(char *argv)
{
	int	i;
	long	i;
	
	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			i++;
		if (argv[i] == '-')
			i++;
		if (argv[i])
			i += 0;  // il n'y a rien ici avant
	}
}
int	is_num(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			i++;
		else if (argv[i] == '-')
			i++;
		else if ((argv[i] >= '0' && argv[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

void is_flag(char *argv, t_data *data)
{
	if (ft_strcmp(argv, "--bench") == 0)
		data->bench.bench_mode = 1;
	else if (ft_strcmp(argv, "--adaptive") == 0)
		data->bench.strategy = 1;
	else if (ft_strcmp(argv, "--simple") == 0)
		data->bench.strategy = 2;
	else if (ft_strcmp(argv, "--medium") == 0)
		data->bench.strategy = 3;
	else if (ft_strcmp(argv, "--complex") == 0)
		data->bench.strategy = 4;
	else
		write (2, "Error", 6);
		write (2, "\n", 2);
}

static char	*join_args(int argc, char **argv, t_data *data)
{
	char	*str_arg;
	char	*tmp;
	int	i;

	str_arg = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			is_flag(argv[i], data);
		else
		{
		tmp = ft_strjoin(str_arg, argv[i]);
		free(str_arg);
		str_arg = ft_strjoin(tmp, " ");
		free(tmp);
		}
		i++;
	}
	return (str_arg);
}


t_list *parsing(int argc, char **argv, t_data *data)
{
	char	*str_arg;
	char	**new_arg;
	
	new_arg = join_arg(argc, argv, data);
	if (!new_arg)
		return ;
	if (is_valid(new_arg))
	{
		new_arg = ft_split(new_arg, ' ');
		return (ft_tolist(new_arg));
	}
	write (2, "Error", 6);
	write (2, "\n", 2);
}
