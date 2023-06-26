/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:18:26 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/26 13:07:29 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*__HEADER FILES__*/
# include <unistd.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

/*___TEXTS_TO_PRINT___*/
# define ARGS_KO 	"Invalid Arguments\n"
# define PRINTER 	"\033[1;30m%ld ms \033[1;31m%d %s\n"
# define FORK_TAKEN "\033[1;33mhas taken a fork"
# define EATING 	"\033[1;32mis eating"
# define SLEEPING 	"\033[1;34mis sleeping"
# define THINKING 	"\033[1;36mis thinking"
# define DIED		"\033[1;31mdied"

/*___OTHERS___*/
# define MALLOC_KO 		0
# define MUTEX_OK 		1
# define TRUE			1
# define FALSE			0
# define LOCKED			0
# define UNLOCKED		1

# define PHILO_C	0
# define TTDIE		1
# define TTEAT		2
# define TTSLEEP	3
# define MEALS_C	4

typedef struct s_data	t_data;
typedef pthread_mutex_t	t_mutex;

/*___STRUCTURE_FOR_EACH_PHILO___*/
typedef struct s_philo {
	int			id;
	int			l_fork;
	int			r_fork;
	long		last_meal;
	long		max_time_to_eat;
	int			time_since_eat;
	int			is_eating;
	t_mutex		eating_mutex;
	int			eat_count;
	pthread_t	thread_id;
	t_data		*c;
}	t_philo;

/*___MAIN_STRUCTURE___*/
typedef struct s_data {
	char		**argv;
	int			argc;
	t_mutex		*forks;
	t_mutex		printing;
	t_mutex		death;
	long		program_start_time;
	long		args[5];
	int			finish;
	t_philo		*philos;
}	t_data;

/*___ACTIONS___*/
void			get_fork(t_philo *phils);
void			eat(t_philo *phils);
void			leave_fork(t_philo *phils);

/*___INIT_DATA___*/
int				init_mutex(t_data *c);
int				init_philo_thread(t_data *c, int i);
int				init_philosophers(t_data *c);

/*___ROUTINES___*/
void			*death_checker(void *phils);
void			*meals_checker(void *phils);
void			*dinner(void *phils);

/*___PARSER___*/
int				valid_range(char **argv);
int				init_args(t_data *c, int argc, char **argv);
void			print_one(long time);

/*___TIME___*/
long			get_time(void);
long			ft_usleep(long wait);
long			time_sum(long start, long delay);
long			time_dif(long old_time);

/*__UTILS__*/
long			ft_atoi_long(const char *str);
int				ft_isdigit(int c);
int				ft_str_is_digit(char *str);
int				ft_strlen(char *str);
int				is_dead(t_philo *philo);
int				print_game(t_philo *phils, char *str, int lock);

#endif
