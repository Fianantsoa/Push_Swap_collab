/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erakotom <erakotom@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-07 13:19:53 by erakotom          #+#    #+#             */
/*   Updated: 2026-04-07 13:19:53 by erakotom         ###   ########.fr       */
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

char	*ft_strjoin_with_space(char *s1, char *s2)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	result = ft_strjoin(tmp, " ");
	free(tmp);
	return (result);
}

t_list	*ft_tolist(char **str)
{
	t_list	*new_node;
	t_list	*head;
	int		*nb;
	int		i;

	i = 0;
	head = NULL;
	while (str[i])
	{
		nb = malloc(sizeof(int));
		if (!nb)
			return (NULL);
		*nb = ft_atoi(str[i]);
		new_node = ft_lstnew(nb);
		if (!new_node)
		{
			free(nb);
			ft_lstclear(&head, free);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		i++;
	}
	return (head);
}
