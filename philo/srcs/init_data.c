/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:07:10 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/26 19:10:45 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_cosas *c)
{
	int	i;

	pthread_mutex_init(&c->printing, NULL);
	pthread_mutex_init(&c->death, NULL);
	c->forks = malloc(sizeof(pthread_mutex_t) * c->philo_c);
	if (!c->forks)
		return (MALLOC_KO);
	pthread_mutex_lock(&c->death);
	i = 0;
	while (i <= c->philo_c)
	{
		pthread_mutex_init(&c->forks[i], NULL);
		i++;
	}
	return (MUTEX_OK);
}

int	init_philosophers(t_cosas *c)
{
	int			i;
	pthread_t	meals_check;

	c->philos = malloc(sizeof(t_philo) * c->philo_c);
	if (!c->philos)
		return (MALLOC_KO);
	i = 0;
	while (i < c->philo_c)
	{
		c->philos[i].id = i + 1;
		c->philos[i].l_fork = (i + 2) % c->philo_c;
		c->philos[i].r_fork = (i + 1) % c->philo_c;
		printf("ID:[%d], LEFT: [%d] RIGHT:[%d]\n", c->philos[i].id, c->philos[i].l_fork, c->philos[i].r_fork);
		gettimeofday(&(c->philos[i].last_meal), NULL);
		c->philos[i].c = c;
		init_thread(c, i);
		i++;
	}
	if (c->meals > 0)
	{
		pthread_create(&meals_check, NULL, &meals_checker, (void *)c);
		pthread_detach(meals_check);
	}
	return (0);
}

int	init_thread(t_cosas *phils, int i)
{
	void		*phi;

	phi = (void *)(&phils->philos[i]);
	if (pthread_create(&phils->philos[i].thread_id, NULL, &dinner, phi))
		return (0);
	pthread_detach(phils->philos[i].thread_id);
	usleep(100);
	return (0);
}
