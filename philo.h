/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:45:08 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/23 02:02:56 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_rules {
	int nb_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int must_eat;
	long start_time;
	int someone_died;
	pthread_mutex_t *forks;
	pthread_mutex_t write_lock;
} t_rules;

typedef struct s_philo {
	int id;
	int meals_eaten;
	long last_meal;
	pthread_t thread;
	t_rules *rules;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
} t_philo;


int	ft_atoi(const char *str, t_rules *philo);
void parsing(char **av, int ac, t_philo *philo);
int	ft_isdigit(int c);
void write_err(t_rules *philo);


#endif