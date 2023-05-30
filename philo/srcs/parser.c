/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:13:08 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/30 14:23:51 by psegura-         ###   ########.fr       */
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

int	init_args(t_cosas *c, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (valid_range(argv) == 1)
	{
		c->philo_c = ft_atoi_long(argv[1]);
		c->ttdie = ft_atoi_long(argv[2]);
		c->tteat = ft_atoi_long(argv[3]);
		c->ttsleep = ft_atoi_long(argv[4]);
		if (argc == 6)
			c->meals = ft_atoi_long(argv[5]);
		else
			c->meals = -1;
		if (c->philo_c < 1 || c->ttdie < 1
			|| c->tteat < 1 || c->ttsleep < 1 || c->meals < -1 || c->meals == 0)
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
