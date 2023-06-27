/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:05:33 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/27 14:12:02 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_checker(void *phils)
{
	t_philo			*philo;

	philo = (t_philo *)phils;
	// if (finish(philo) == TRUE)
	// {
	// 	pthread_mutex_unlock(&(philo->c->death));
	// 	return (NULL);
	// }
	while (finish(philo) != TRUE)
	{
		if (is_dead(philo) == TRUE)
		{
			//TODO: cambiar a LOCKED, y cerrar bien todos los hilos.
			print_game(philo, DIED, UNLOCKED);
			philo->c->finish = TRUE;
			//? pthread_mutex_lock(&philo->c->printing); 
			// pthread_mutex_unlock(&(philo->c->death));
			return (NULL);
		}
		ft_usleep(1);
	}
	return ((void *)1);
}

void	*meals_checker(void *phils)
{
	t_data	*c;
	int		i;

	c = (t_data *)phils;
	while (TRUE)
	{
		i = 0;
		while (i < c->args[PHILO_C])
		{
			if (had_all_meals(c, i) == FALSE)
				break ;
			i++;
		}
		if (i == c->args[PHILO_C])
		{
			pthread_mutex_lock(&c->printing);
			printf("---------------------\n");
			printf("YA HEMOS COMIDO TODOS\n");
			printf("---------------------\n");
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
	// pthread_t	th_death_checker;

	philo = (t_philo *)phils;
	philo->last_meal = philo->c->program_start_time;
	philo->max_time_to_eat = time_sum(philo->last_meal, philo->c->args[TTDIE]);
	// pthread_create(&th_death_checker, NULL, &death_checker, phils);
	// pthread_detach(th_death_checker);
	if (philo->id % 2 == 0)
		usleep(500);
	while (philo->c->finish != TRUE)
	{
		get_fork(philo);
		eat(philo);
		leave_fork(philo);
		printf("tamos vivos\n");
	}
	// pthread_join(th_death_checker, NULL);
	return (NULL);
}
