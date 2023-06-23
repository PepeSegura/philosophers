/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:05:33 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/23 22:44:59 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_checker(void *phils)
{
	t_philo			*philo;
	struct timeval	time_checker;

	philo = (t_philo *)phils;
	while (TRUE)
	{
		gettimeofday(&time_checker, NULL);
		pthread_mutex_lock(&(philo->c->printing));
		if (philo->is_eating == 0 && (timeval_to_useconds(philo->max_time_to_eat)
				< timeval_to_useconds(time_checker)))
		{
			pthread_mutex_unlock(&(philo->c->printing));
			print_game(philo, DIED, LOCKED);
			pthread_mutex_unlock(&(philo->c->death));
			return ((void *) 0);
		}
		pthread_mutex_unlock(&(philo->c->printing));
		ft_usleep(1000);
	}
	return ((void *) 1);
}

void	*meals_checker(void *phils)
{
	t_cosas	*c;
	int		i;

	c = (t_cosas *)phils;
	while (TRUE)
	{
		i = 0;
		while (i < c->args[PHILO_C])
		{
			if (c->philos[i].eat_count >= c->args[MEALS_C])
				i++;
			else
				break ;
		}
		if (i == c->args[PHILO_C])
		{

			pthread_mutex_unlock(&c->death);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

void	*dinner(void *phils)
{
	t_philo			*philo;
	pthread_t		th_death_checker;

	philo = (t_philo *)phils;
	philo->last_meal = philo->c->program_start_time;
	philo->max_time_to_eat = time_sum(philo->last_meal, philo->c->args[TTDIE] * 1000);
	pthread_create(&th_death_checker, NULL, &death_checker, phils);
	pthread_detach(th_death_checker);
	if (philo->id % 2 == 0)
		usleep(550);
	while (TRUE)
	{
		get_fork(philo);
		eat(philo);
		leave_fork(philo);
	}
	return (NULL);
}
