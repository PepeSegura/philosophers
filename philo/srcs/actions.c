/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 05:36:27 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/18 06:11:23 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *phils)
{
	pthread_mutex_lock(&phils->c->forks[phils->l_fork]);
	print_game(phils, "has taken a fork", UNLOCKED);
	pthread_mutex_lock(&phils->c->forks[phils->r_fork]);
	print_game(phils, "has taken a fork", UNLOCKED);
}

void	eat(t_philo *phils)
{
	phils->is_eating = 1;
	print_game(phils, "is eating", UNLOCKED);
	gettimeofday(&phils->last_meal, NULL);
	phils->max_time_to_eat = time_sum(phils->last_meal,
			phils->c->ttdie * 1000);
	phils->eat_count++;
	usleep(phils->c->tteat * 1000);
	phils->is_eating = 0;
}

void	leave_fork(t_philo *phils)
{
	print_game(phils, "is sleeping", UNLOCKED);
	pthread_mutex_unlock(&phils->c->forks[phils->l_fork]);
	pthread_mutex_unlock(&phils->c->forks[phils->r_fork]);
	usleep(phils->c->ttsleep * 1000);
	print_game(phils, "is thinking", UNLOCKED);
}
