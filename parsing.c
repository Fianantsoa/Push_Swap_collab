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

int	is_valid(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_valid_int(argv[i]))
			return (0);
		i++;
	}
	if (has_duplicates(argv))
		return (0);
	return (1);
}

static char	*join_args(int argc, char **argv, t_data *data)
{
	char	*str_arg;
	int		i;

	str_arg = ft_strdup("");
	i = 0;
	while (argv[i])
	{
		if (ft_strncmp (argv[i], "./push_swap", 11) == 0)
		{
			i += 1;
			break ;
		}
		i++;
	}
	while (i < argc)
	{
		flag_search(argv[i], data);
		str_arg = ft_strjoin_with_space(str_arg, argv[i]);
		i++;
	}
	argc ++;
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

t_list	*parsing(int argc, char **argv, t_data *data)
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
	return (NULL);
}
