/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:14:14 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/08 20:32:29 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(char **av, int ac, t_rules *arg)
{
	int (i), (j);
	i = 1;
	j = 0;
	if (ac - 1 > 5 || ac - 1 < 4)
		write_err(arg);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+')
				j++;
			if (ft_isdigit(av[i][j]) == 0)
				write_err(arg);
			j++;
		}
		i++;
	}
	arg->nb_philo = ft_atoi(av[1], arg, 0);
	arg->t_die = ft_atoi(av[2], arg, 0);
	arg->t_eat = ft_atoi(av[3], arg, 0);
	arg->t_sleep = ft_atoi(av[4], arg, 0);
	if (--ac == 5)
		arg->must_eat = ft_atoi(av[5], arg, 0);
}

void	loop_init(t_rules *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = get_time_ms();
		philo[i].left_fork = &arg->forks[i];
		philo[i].right_fork = &arg->forks[(i + 1) % arg->nb_philo];
		philo[i].arg = arg;
		i++;
	}
	arg->philo = philo;
}

void	init_all(t_rules *arg)
{
	int		i;
	t_philo	*philo;

	i = 0;
	arg->forks = malloc(sizeof(pthread_mutex_t) * (arg->nb_philo + 1));
	philo = malloc(sizeof(t_philo) * (arg->nb_philo + 1));
	if (!arg->forks || !philo)
		return ;
	while (i < arg->nb_philo)
	{
		if (pthread_mutex_init(&arg->forks[i], NULL) != 0)
			return ;
		i++;
	}
	pthread_mutex_init(&arg->write_lock, NULL);
	pthread_mutex_init(&arg->meal_lock, NULL);
	pthread_mutex_init(&arg->detach, NULL);
	if (arg->nb_philo > 1)
		arg->loop = 1;
	else
		arg->loop = 0;
	loop_init(arg, philo);
}

void	must_phile_eat(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->arg->meal_lock);
	if (philo[i].meals_eaten >= philo->arg->must_eat)
	{
		pthread_mutex_lock(&philo->arg->detach);
		philo->arg->loop = 0;
		pthread_mutex_unlock(&philo->arg->detach);
		pthread_mutex_unlock(&philo->arg->meal_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->arg->meal_lock);
}

void	monitor(t_philo *philo)
{
	int		i;
	long	time;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->arg->meal_lock);
		time = get_time_ms() - philo[i].last_meal;
		pthread_mutex_unlock(&philo->arg->meal_lock);
		if (time > philo->arg->t_die)
		{
			pthread_mutex_lock(&philo->arg->detach);
			philo->arg->loop = 0;
			print_isdied(philo, "is died");
			pthread_mutex_unlock(&philo->arg->detach);
			pthread_mutex_lock(&philo->arg->write_lock);
			break ;
		}
		if (philo->arg->must_eat)
			must_phile_eat(philo, i);
		i++;
		if (i >= philo->arg->nb_philo - 1)
			i = 0;
		usleep(500);
	}
}
