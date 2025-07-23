/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:44:54 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/23 23:28:29 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop_init(t_rules *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = 0;
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
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->nb_philo);
	philo = malloc(sizeof(t_philo) * arg->nb_philo);
	if (!arg->forks || !philo)
		return ;
	while (i < arg->nb_philo)
	{
		if (pthread_mutex_init(&arg->forks[i], NULL) != 0)
			return ;
		i++;
	}
	pthread_mutex_init(&arg->write_lock, NULL);
	pthread_mutex_init(&arg->someone_died, NULL);
	loop_init(arg, philo);
}

int	main(int ac, char **av)
{
	t_rules	*arg;

	arg = malloc(sizeof(t_rules));
	memset(arg, 0, sizeof(t_rules));
	parsing(av, ac, arg);
	init_all(arg);
	// printf("%d\n", arg->philo[2].id);
	free(arg);
}
