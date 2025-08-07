/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:00:44 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/07 17:56:34 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(300);
	while (check_loob(philo->arg))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	print_message(philo, "eating");
	usleep(philo->arg->t_eat * 990);
	pthread_mutex_lock(&philo->arg->meal_lock);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->arg->meal_lock);
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "sleeping");
	usleep(philo->arg->t_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	print_message(philo, "thinking");
}
