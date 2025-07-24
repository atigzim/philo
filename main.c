/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:44:54 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/25 00:51:36 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eating(t_rules *arg)
{
	t_philo *philo;

	philo = arg->philo;
	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&arg->write_lock);
	printf("%d %s\n", philo->id, "has taken a fork");
	printf("%d %s\n", philo->id, "eating");
	pthread_mutex_unlock(&arg->write_lock);
	useelp(arg->t_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}

void thinking(t_rules *arg)
{
	t_philo *philo;

	philo = arg->philo;
	pthread_mutex_lock(&arg->write_lock);
	printf("%d %s\n", philo->id, "thinking");
	pthread_mutex_unlock(&arg->write_lock);
	
}
void *routine()
{
	while (1)
	{
		
	}
	
}
void	create_thread()
{
	
}

int	main(int ac, char **av)
{
	t_rules	*arg;

	arg = malloc(sizeof(t_rules));
	memset(arg, 0, sizeof(t_rules));
	parsing(av, ac, arg);
	init_all(arg);
	// printf("%ld\n", get_time_ms());
	free(arg);
}
