/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:41:05 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/27 13:41:44 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	had_all_meals(t_data *c, int i)
{
	int	meals_count;

	pthread_mutex_lock(&(c->philos[i].eating_mutex));
	meals_count = c->philos[i].eat_count;
	pthread_mutex_unlock(&(c->philos[i].eating_mutex));
	if (meals_count < c->args[MEALS_C])
		return (FALSE);
	return (TRUE);
}

int	finish(t_philo *philo)
{
	int	finish;

	pthread_mutex_lock(&(philo->eating_mutex));
	finish = philo->c->finish;
	pthread_mutex_unlock(&(philo->eating_mutex));
	if (finish == TRUE)
		return (TRUE);
	return (FALSE);
}

int	is_dead(t_philo *philo)
{
	int		is_eating;
	long	limit_time;

	pthread_mutex_lock(&(philo->eating_mutex));
    is_eating = philo->is_eating;
	limit_time = philo->max_time_to_eat;
    pthread_mutex_unlock(&(philo->eating_mutex));
	if (is_eating == 0 && (get_time() > limit_time))
		return (TRUE);
	return (FALSE);
}
