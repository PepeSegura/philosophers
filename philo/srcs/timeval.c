/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 05:49:14 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/24 02:13:13 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	time_sum(struct timeval time_sec, long time_usec)
{
	struct timeval	time_out;

	time_out.tv_usec = time_sec.tv_usec + time_usec;
	if (time_out.tv_usec < 1000000)
		time_out.tv_sec = time_sec.tv_sec;
	else
	{
		time_out.tv_sec = time_sec.tv_sec + 1;
		time_out.tv_usec = time_out.tv_usec - 1000000;
	}
	return (time_out);
}

long	timeval_to_useconds(struct timeval time_sec)
{
	return ((time_sec.tv_sec * (long)1000) + (time_sec.tv_usec / 1000));
}

long	time_dif(struct timeval time_usec)
{
	struct timeval	time_sec;

	gettimeofday(&time_sec, NULL);
	return (time_sec.tv_usec - time_usec.tv_usec
		+ (time_sec.tv_sec - time_usec.tv_sec) * 1000000);
}
