/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:44:54 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/25 05:28:06 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->arg->write_lock);
	printf(" %ld %d %s\n", get_time_ms() - philo->start_time ,philo->id, "has taken a right_fork");
	pthread_mutex_lock(philo->left_fork);
	printf("%d %s\n", philo->id, "has taken a left_fork");
	pthread_mutex_unlock(&philo->arg->write_lock);
	printf("%d %s\n", philo->id, "eating");
	usleep(philo->arg->t_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->write_lock);
	printf("%d %s\n", philo->id, "thinking");
	pthread_mutex_unlock(&philo->arg->write_lock);
	
}

void sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->write_lock);
	printf("%d %s\n", philo->id, "sleeping");
	pthread_mutex_unlock(&philo->arg->write_lock);
	usleep(philo->arg->t_sleep * 1000);
}

void *routine(void *arg)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		printf("......%d.....\n", philo->id);
		if(philo->id % 2 == 0)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
		else
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
		if(i >= philo->arg->nb_philo)
			i = 0;
		else
			i++;
	}
	return (NULL);
}

void	create_thread(t_rules *arg)
{
	int i;
	t_philo *philo;

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
	if ((pthread_join(philo[--i].thread, NULL)) != 0)
	{
		printf("Failed to join thread for philo %d\n", i + 1);
		return ;
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
	free(arg);
}
