/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:07:10 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/24 17:29:50 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *c)
{
	int	i;

	pthread_mutex_init(&c->printing, NULL);
	pthread_mutex_init(&c->death, NULL);
	c->forks = malloc(sizeof(pthread_mutex_t) * c->args[PHILO_C]);
	if (!c->forks)
		return (MALLOC_KO);
	pthread_mutex_lock(&c->death);
	i = 0;
	while (i <= c->args[PHILO_C])
	{
		pthread_mutex_init(&c->forks[i], NULL);
		// pthread_mutex_init(&c->eating[i], NULL);
		i++;
	}
	return (MUTEX_OK);
}

int	init_philosophers(t_data *c)
{
	int			i;
	// pthread_t	meals_check;

	c->philos = malloc(sizeof(t_philo) * c->args[PHILO_C]);
	if (!c->philos)
		return (MALLOC_KO);
	i = 0;
	while (i < c->args[PHILO_C])
	{
		c->philos[i].id = i + 1;
		c->philos[i].l_fork = (i + 2) % c->args[PHILO_C];
		c->philos[i].r_fork = (i + 1) % c->args[PHILO_C];
		dprintf(2, "ID:[%d], LEFT: [%d] RIGHT:[%d]\n", c->philos[i].id,
				c->philos[i].l_fork, c->philos[i].r_fork);
		c->philos[i].last_meal = get_time();
		c->philos[i].c = c;
		init_philo_thread(c, i);
		i++;
	}
	// if (c->args[MEALS_C] > 0)
	// {
	// 	pthread_create(&meals_check, NULL, &meals_checker, (void *)c);
	// 	pthread_detach(meals_check);
	// }
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
