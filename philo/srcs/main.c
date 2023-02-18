/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:11:11 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/18 07:06:39 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_cosas	c;

	memset(&c, 0, sizeof(t_cosas));
	c.argc = argc;
	c.argv = argv;
	if (argc == 5 || argc == 6)
	{
		if (init_args(&c) == 0)
		{
			if (c.philo_c != 1)
			{
				mutex(&c);
				philosophers(&c);
				pthread_mutex_lock(&c.death);
			}
			else
				printf("0ms philo 1 died\n");
		}
		else
			printf("Invalid Arguments\n");
	}
	else
		printf(USAGE);
	return (0);
}
