#ifndef PHILO_H
# define PHILO_H
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_args {
	int num_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int max_meals; // optional
	long start_time;
	int someone_died;

	pthread_mutex_t *forks;
	pthread_mutex_t write_lock;
	pthread_mutex_t dead_lock;
	pthread_mutex_t meal_lock;
} t_arg;

typedef struct s_philo {
	int id;
	int meals_eaten;
	long last_meal;

	t_arg *args;
	pthread_t thread;

	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
} t_philo;


long	ft_atoi(const char *str, t_arg *philo);
void parsing(char **av, int ac, t_arg *philo);
int	ft_isdigit(int c);


#endif