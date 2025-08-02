/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:14:06 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/02 13:16:20 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a right_fork");
	print_message(philo, "has taken a left_fork");
	print_message(philo, "eating");
	usleep(philo->arg->t_eat * 990);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->meals_eaten++;
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "sleeping");
	usleep(philo->arg->t_sleep * 1000);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(300);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	create_thread(t_rules *arg)
{
	int		i;
	long	time;
	t_philo	*philo;

	i = 0;
	philo = arg->philo;
	while (i < arg->nb_philo)
	{
		philo[i].start_time = get_time_ms();
		if ((pthread_create(&philo[i].thread, NULL, routine, &philo[i])) != 0)
		{
			printf("Failed to create thread for philo %d\n", i + 1);
			return ;
		}
		i++;
	}
	i = 0;
	while (1)
	{
		time = get_time_ms() - philo[i].last_meal;
		if (time > philo->arg->t_die)
		{
			print_message(philo, "is died");
			break ;
		}
		if (i < philo->arg->nb_philo - 1)
			i++;
		i--;
		if (philo->arg->must_eat && philo[i].id % 2 != 0)
		{
			if (philo[i].meals_eaten >= philo->arg->must_eat)
				break ;
		}
	}
}

int	main(int ac, char **av)
{
	t_rules	*arg;

	arg = malloc(sizeof(t_rules));
	memset(arg, 0, sizeof(t_rules));
	parsing(av, ac, arg);
	init_all(arg);
	create_thread(arg);
}
