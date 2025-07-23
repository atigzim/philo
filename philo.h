/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 02:07:36 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/23 22:28:35 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_philo {
	
	int id;
	int meals_eaten;
	long last_meal;
	struct s_rules *arg;
	pthread_t thread;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
} t_philo;

typedef struct s_rules {
	int nb_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int must_eat;
	t_philo *philo;
	pthread_mutex_t someone_died;
	pthread_mutex_t *forks;
	pthread_mutex_t write_lock;
} t_rules;



int	ft_atoi(const char *str, t_rules *philo);
void parsing(char **av, int ac, t_rules *philo);
int	ft_isdigit(int c);
void write_err(t_rules *philo);
void init_all(t_rules *arg);


#endif