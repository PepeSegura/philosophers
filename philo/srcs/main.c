/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:11:11 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/30 18:56:16 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_cosas	c;

	memset(&c, 0, sizeof(t_cosas));
	if (init_args(&c, argc, argv))
	{
		if (c.philo_c == 1)
			print_one(c.ttdie);
		else
		{
			init_mutex(&c);
			init_philosophers(&c);
			pthread_mutex_lock(&c.death);
		}
	}
	else
		printf(ARGS_KO);
	return (0);
}

