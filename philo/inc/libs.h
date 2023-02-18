/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:18:08 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/18 00:51:47 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H

//Write, Read
# include <unistd.h>

//Usleep
# include <unistd.h>

/*
Pthread_create, Pthread_detach, Pthread_join
Pthread_mutex_init, Pthread_mutex_destroy
Pthread_mutex_lock, Pthread_mutex_unlock
*/
# include <pthread.h>

//Gettimeofday
# include <sys/time.h>

//Printf
# include <stdio.h>

//Malloc, Free, Exit
# include <stdlib.h>

//Memset
# include <string.h>

//Others
# include <limits.h>
#endif
