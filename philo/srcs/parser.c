/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:13:08 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/18 02:00:33 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_range(t_cosas *c)
{
	int	i;

	i = 1;
	while (c->argv[i])
	{
		if (ft_strlen(c->argv[i]) > 12
			|| (ft_atoi_long(c->argv[i]) < INT_MIN
				|| ft_atoi_long(c->argv[i]) > INT_MAX))
			return (0);
		i++;
	}
	return (1);
}

int	init_args(t_cosas *c)
{
	if (valid_range(c) == 1)
	{
		gettimeofday(&c->program_start_time, NULL);
		c->philo_c = ft_atoi_long(c->argv[1]);
		c->ttdie = ft_atoi_long(c->argv[2]);
		c->tteat = ft_atoi_long(c->argv[3]);
		c->ttsleep = ft_atoi_long(c->argv[4]);
		if (c->argc == 6)
			c->meals = ft_atoi_long(c->argv[5]);
		else
			c->meals = -1;
		if ((c->philo_c < 1 || c->philo_c > 200) || c->ttdie < 1
			|| c->tteat < 1 || c->ttsleep < 1 || c->meals < -1 || c->meals == 0)
			return (-1);
		return (0);
	}
	return (-1);
}
