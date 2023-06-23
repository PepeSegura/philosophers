/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:13:08 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/24 00:39:52 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_range(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 12
			|| (ft_atoi_long(argv[i]) < INT_MIN
				|| ft_atoi_long(argv[i]) > INT_MAX)
			|| !ft_str_is_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	init_args(t_data *c, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (valid_range(argv) == 1)
	{
		c->args[PHILO_C] = ft_atoi_long(argv[1]);
		c->args[TTDIE] = ft_atoi_long(argv[2]);
		c->args[TTEAT] = ft_atoi_long(argv[3]);
		c->args[TTSLEEP] = ft_atoi_long(argv[4]);
		if (argc == 6)
			c->args[MEALS_C] = ft_atoi_long(argv[5]);
		else
			c->args[MEALS_C] = -1;
		if (c->args[PHILO_C] < 1 || c->args[TTDIE] < 1
			|| c->args[TTEAT] < 1 || c->args[TTSLEEP] < 1 || c->args[MEALS_C] < -1 || c->args[MEALS_C] == 0)
			return (0);
		gettimeofday(&c->program_start_time, NULL);
		return (1);
	}
	return (0);
}

void	print_one(long time)
{
	printf("\033[1;30m0 ms \033[1;31m 1 \033[1;33mhas taken a fork\n");
	printf("\033[1;30m%ld ms \033[1;31m 1 \033[1;31mdied\n", ft_usleep(time));
}
