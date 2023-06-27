/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:11:11 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/27 16:45:19 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*c;

	c = malloc(sizeof(t_data));
	memset(c, 0, sizeof(t_data));
	if (init_args(c, argc, argv))
	{
		if (c->args[PHILO_C] == 1)
			print_one(c->args[TTDIE]);
		else
		{
			init_mutex(c);
			init_philosophers(c);
			init_checkers(c);
			pthread_mutex_lock(&c->death);
		}
	}
	else
	{
		free(c);
		printf(ARGS_KO);
	}
	return (0);
}
