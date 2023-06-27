/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:11:11 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/27 13:58:22 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_checkers(t_data *c)
{
	pthread_t	meals_check;

	if (c->args[MEALS_C] > 0)
	{
		pthread_create(&meals_check, NULL, &meals_checker, (void *)c);
		pthread_detach(meals_check);
		pthread_join(meals_check, NULL);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	c;

	memset(&c, 0, sizeof(t_data));
	if (init_args(&c, argc, argv))
	{
		if (c.args[PHILO_C] == 1)
			print_one(c.args[TTDIE]);
		else
		{
			init_mutex(&c);
			init_philosophers(&c);
			init_checkers(&c);
			pthread_mutex_lock(&c.death);
		}
	}
	else
		printf(ARGS_KO);
	return (0);
}
