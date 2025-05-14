#ifndef PHILO_H
# define PHILO_H
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_arg
{
	int philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int t_p_eat;
}t_arg;

long	ft_atoi(const char *str, t_arg *philo);
void parsing(char **av, int ac, t_arg *philo);
int	ft_isdigit(int c);


#endif