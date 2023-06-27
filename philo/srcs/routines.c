/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:05:33 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/27 16:43:24 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_checker_aux(t_data *c, int i)
{
	pthread_mutex_lock(&c->m_finish);
	c->finish = TRUE;
	pthread_mutex_unlock(&c->m_finish);
	print_game(&c->philos[i], DIED, LOCKED);
	pthread_mutex_unlock(&c->death);
	return (NULL);
}

void	*death_checker(void *phils)
{
	t_data	*c;
	int		i;

	c = (t_data *)phils;
	while (TRUE)
	{
		if (finish(&c->philos[0]) == TRUE)
			return (NULL);
		i = 0;
		while (i < c->args[PHILO_C])
		{
			if (is_dead(&c->philos[i]) == FALSE)
				i++;
			else
				return (death_checker_aux(c, i));
		}
		if (i == c->args[PHILO_C])
		{
			ft_usleep(1);
			continue ;
		}
	}
	return (NULL);
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
			pthread_mutex_lock(&c->m_finish);
			c->finish = TRUE;
			pthread_mutex_unlock(&c->m_finish);
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

	philo = (t_philo *)phils;
	pthread_mutex_lock(&(philo->eating_mutex));
	philo->last_meal = philo->c->program_start_time;
	philo->max_time_to_eat = time_sum(philo->last_meal, philo->c->args[TTDIE]);
	pthread_mutex_unlock(&(philo->eating_mutex));
	if (philo->id % 2 == 0)
		usleep(500);
	while (finish(philo) == FALSE)
	{
		get_fork(philo);
		eat(philo);
		leave_fork(philo);
	}
	return (NULL);
}
