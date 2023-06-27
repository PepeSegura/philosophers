/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:07:10 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/27 16:45:30 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *c)
{
	int	i;

	pthread_mutex_init(&c->printing, NULL);
	pthread_mutex_init(&c->death, NULL);
	pthread_mutex_init(&c->m_finish, NULL);
	c->forks = malloc(sizeof(t_mutex) * c->args[PHILO_C]);
	if (!c->forks)
		return (MALLOC_KO);
	pthread_mutex_lock(&c->death);
	i = 0;
	while (i <= c->args[PHILO_C])
	{
		pthread_mutex_init(&c->forks[i], NULL);
		i++;
	}
	return (MUTEX_OK);
}

int	init_checkers(t_data *c)
{
	pthread_t	meals_check;
	pthread_t	death_check;

	if (c->args[MEALS_C] > 0)
	{
		pthread_create(&meals_check, NULL, &meals_checker, (void *)c);
		pthread_join(meals_check, NULL);
	}
	pthread_create(&death_check, NULL, &death_checker, (void *)c);
	pthread_join(death_check, NULL);
	return (0);
}

int	init_philosophers(t_data *c)
{
	int			i;

	c->philos = malloc(sizeof(t_philo) * c->args[PHILO_C]);
	if (!c->philos)
		return (MALLOC_KO);
	i = 0;
	while (i < c->args[PHILO_C])
	{
		c->philos[i].id = i + 1;
		c->philos[i].l_fork = (i + 2) % c->args[PHILO_C];
		c->philos[i].r_fork = (i + 1) % c->args[PHILO_C];
		c->philos[i].last_meal = get_time();
		c->philos[i].c = c;
		pthread_mutex_init(&(c->philos[i].eating_mutex), NULL);
		init_philo_thread(c, i);
		i++;
	}
	return (0);
}

int	init_philo_thread(t_data *phils, int i)
{
	void	*phi;

	phi = (void *)(&phils->philos[i]);
	if (pthread_create(&phils->philos[i].thread_id, NULL, &dinner, phi))
		return (0);
	pthread_detach(phils->philos[i].thread_id);
	usleep(100);
	return (0);
}
