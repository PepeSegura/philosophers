/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:07:02 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/24 15:06:59 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_sum(long start, long delay)
{
	return (start + delay);
}

long	time_dif(long old_time)
{
	return (get_time() - old_time);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	ft_usleep(long wait)
{
	long	limit;

	limit = get_time() + wait;
	while (1)
	{
		if (get_time() >= limit)
			break ;
		usleep(200);
	}
	return (wait);
}
