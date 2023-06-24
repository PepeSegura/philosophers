/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:05:33 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/24 17:29:52 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_checker(void *phils)
{
	t_philo			*philo;
	long			actual_time;

	philo = (t_philo *)phils;
	while (TRUE)
	{
		actual_time = get_time();
		if (philo->is_eating == 0 && (philo->max_time_to_eat < actual_time))
		{
			print_game(philo, DIED, LOCKED);
			pthread_mutex_unlock(&(philo->c->death));
			return ((void *)0);
		}
		ft_usleep(1);
	}
	return ((void *)1);
}

void	*meals_checker(void *phils)
{
	t_data	*c;
	int		i;
	// int		max ;

	c = (t_data *)phils;
	while (TRUE)
	{
		i = 0;
		while (i < c->args[PHILO_C])
		{
			dprintf(2, "PHILO[%d] MEALS[%d]\n", i, c->philos[i].eat_count);
			if (c->philos[i].eat_count < c->args[MEALS_C])
				break ;
			i++;
		}
		if (i == c->args[PHILO_C])
		{
			pthread_mutex_unlock(&c->death);
			break ;
		}
		ft_usleep(1);
	}
	return (NULL);
}

void	*dinner(void *phils)
{
	t_philo		*philo;
	pthread_t	th_death_checker;

	philo = (t_philo *)phils;
	philo->last_meal = philo->c->program_start_time;
	philo->max_time_to_eat = time_sum(philo->last_meal, philo->c->args[TTDIE]);
	pthread_create(&th_death_checker, NULL, &death_checker, phils);
	pthread_detach(th_death_checker);
	if (philo->id % 2 == 0)
		usleep(500);
	while (TRUE)
	{
		get_fork(philo);
		eat(philo);
		leave_fork(philo);
	}
	return (NULL);
}
