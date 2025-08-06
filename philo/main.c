/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:14:06 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/06 21:17:39 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detach_th(t_rules *arg)
{
	int	i;

	i = 0;
	while (i < arg->nb_philo)
	{
		pthread_detach(arg->philo[i].thread);
		i++;
	}
}

void destr(t_rules *arg)
{
	int i;

	i = 0;
	while (i < arg->nb_philo)
	{
		pthread_mutex_destroy(&arg->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&arg->write_lock);
}


void	create_thread(t_rules *arg)
{
	int		i;
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
	monitor(philo);

}

void monitor(t_philo *philo)
{
	int	i;
	long	time;

	i = 0;
	while (1)
	{
		time = get_time_ms() - philo[i].last_meal;
		if (time > philo->arg->t_die)
		{
			print_message(philo, "is died");
			pthread_mutex_lock(&philo->arg->write_lock);
			break ;
		}
		if (i < philo->arg->nb_philo)
			i++;
		i--;
		if (philo->arg->must_eat && philo[i].id % 2 != 0)
		{
			if (philo[i].meals_eaten >= philo->arg->must_eat)
			{
				pthread_mutex_lock(&philo->arg->write_lock);
				break ;
			}
		}
		usleep(1000);
	}
	// usleep(1000000);
}

int	main(int ac, char **av)
{
	t_rules	*arg;

	arg = malloc(sizeof(t_rules));
	memset(arg, 0, sizeof(t_rules));
	parsing(av, ac, arg);
	init_all(arg);
	create_thread(arg);
	detach_th(arg);
	destr(arg);  
	free(arg->forks);
	free(arg->philo);        
	free(arg);
}
