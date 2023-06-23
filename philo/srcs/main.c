/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:11:11 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/24 01:12:24 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_args(t_data *c)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("Arg[%d]: [%ld]\n", i, c->args[i]);
		i++;
	}
	printf("Start_time: [%ld]\n", timeval_to_useconds(c->program_start_time));
}

int	main(int argc, char **argv)
{
	t_data	c;

	memset(&c, 0, sizeof(t_data));
	if (init_args(&c, argc, argv))
	{
		print_args(&c);
		if (c.args[PHILO_C] == 1)
			print_one(c.args[TTDIE]);
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

