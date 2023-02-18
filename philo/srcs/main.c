/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:11:11 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/18 06:15:21 by psegura-         ###   ########.fr       */
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
			mutex(&c);
			philosophers(&c);
			pthread_mutex_lock(&c.death);
		}
		else
			printf("Invalid Arguments\n");
	}
	else
		printf(USAGE);
	return (0);
}

			// printf("philo_c:	[%ld]\n", c.philo_c);
			// printf("ttdie:		[%ld]\n", c.ttdie);
			// printf("tteat:		[%ld]\n", c.tteat);
			// printf("ttsleep:	[%ld]\n", c.ttsleep);
			// printf("meals:		[%ld]\n", c.meals);
			// printf("start_time:	[%ld]\n", c.program_start_time.tv_sec);