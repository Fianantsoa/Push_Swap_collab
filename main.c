/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:21:32 by erakotom          #+#    #+#             */
/*   Updated: 2026/04/01 15:19:41 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;
	int	i;
	static char *arg;
	

	data.stack_a = NULL;
    data.stack_b = NULL;
    data.bench.total_ops = 0;
    data.bench.bench_mode = 0;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			data.bench.bench_mode = 1;
		// else if (ft_strncmp(argv[i], "--simple", 9) == 0)
		// 	data.algo = 1;
		// else if (ft_strncmp(argv[i], "--medium", 9) == 0)
		// 	data.algo = 2;
		// else if (ft_strncmp(argv[i], "--complex", 10) == 0)
		// 	data.algo = 3;
		// else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
		// 	data.algo = 4;
		else
			i++;
	}
	// while (i < argc)
	// {
	// 	if ()
	// 	arg = ft_strjoin(argv[i], argv[i + 1]);
	// }

}
