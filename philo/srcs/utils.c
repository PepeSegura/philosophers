/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:02:02 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/26 12:37:17 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi_long(const char *str)
{
	int				i;
	long long int	dest;
	int				sign;

	i = 0;
	dest = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-'
			|| str[i + 1] == '+'))
		return (0);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		dest = dest * 10;
		dest = dest + str[i] - 48;
		i++;
	}
	return (dest * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_game(t_philo *phils, char *str, int lock)
{
	pthread_mutex_lock(&phils->c->printing);
	if (is_dead(phils) == FALSE)
		printf(PRINTER, time_dif(phils->c->program_start_time), phils->id, str);
	else
		printf(PRINTER, time_dif(phils->c->program_start_time), phils->id, DIED);
	if (lock == UNLOCKED)
		pthread_mutex_unlock(&phils->c->printing);
	return (0);
}
