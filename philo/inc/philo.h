/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:18:26 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/18 06:13:48 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*__HEADER FILES__*/
# include "philo.h"
# include "libs.h"

# define USAGE "USAGE:\n\t./philo n_philos ttdie tteat ttsleep [n_eats_each]\n"

# define MALLOC_KO 		0
# define MUTEX_OK 		1
# define TRUE			1
# define FALSE			0
# define LOCKED			0
# define UNLOCKED		1

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	struct timeval	last_meal;
	struct timeval	max_time_to_eat;
	int				time_since_eat;
	int				is_eating;
	int				eat_count;
	pthread_t		thread_id;
	struct s_cosas	*c;
}	t_philo;

/*__STRUCT_STORE_NUMBERS__*/
typedef struct s_cosas {
	char			**argv;
	int				argc;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printing;
	pthread_mutex_t	death;
	struct timeval	program_start_time;
	long			philo_c;
	long			ttdie;
	long			tteat;
	long			ttsleep;
	long			meals;
	t_philo			*philos;
}	t_cosas;

/*___ACTIONS___*/
void			get_fork(t_philo *phils);
void			eat(t_philo *phils);
void			leave_fork(t_philo *phils);

/*___INIT_DATA___*/
int				mutex(t_cosas *c);
int				thread(t_cosas *c, int i);
int				philosophers(t_cosas *c);

/*___MAIN_LOOPS___*/
void			*death_checker(void *phils);
void			*meals_checker(void *phils);
void			*dinner(void *phils);

/*___PARSER___*/
int				valid_range(t_cosas *c);
int				init_args(t_cosas *c);

/*___TIMEVAL___*/
long			get_time(void);
struct timeval	time_sum(struct timeval time_sec, long time_usec);
long			timeval_to_useconds(struct timeval time_sec);
long			time_dif(struct timeval time_usec);

/*__UTILS__*/
long			ft_atoi_long(const char *str);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
int				print_game(t_philo *phils, char *str, int lock);

#endif
