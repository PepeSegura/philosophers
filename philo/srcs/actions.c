/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 05:36:27 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/24 16:36:55 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *phils)
{
	pthread_mutex_lock(&phils->c->forks[phils->l_fork]);
	print_game(phils, FORK_TAKEN, UNLOCKED);
	pthread_mutex_lock(&phils->c->forks[phils->r_fork]);
	print_game(phils, FORK_TAKEN, UNLOCKED);
}

void	eat(t_philo *phils)
{
	// pthread_mutex_lock(&phils->c->printing);
	phils->is_eating = 1;
	// pthread_mutex_unlock(&phils->c->printing);
	print_game(phils, EATING, UNLOCKED);
	phils->last_meal = get_time();
	phils->max_time_to_eat = time_sum(phils->last_meal, phils->c->args[TTDIE]);
	phils->eat_count++;
	ft_usleep(phils->c->args[TTEAT]);
	// pthread_mutex_lock(&phils->c->printing);
	phils->is_eating = 0;
	// pthread_mutex_unlock(&phils->c->printing);
}

void	leave_fork(t_philo *phils)
{
	print_game(phils, SLEEPING, UNLOCKED);
	pthread_mutex_unlock(&phils->c->forks[phils->l_fork]);
	pthread_mutex_unlock(&phils->c->forks[phils->r_fork]);
	ft_usleep(phils->c->args[TTSLEEP]);
	print_game(phils, THINKING, UNLOCKED);
}
