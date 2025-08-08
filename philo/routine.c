/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:00:44 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/08 20:25:33 by atigzim          ###   ########.fr       */
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

void	ft_usleep(int time, t_philo *philo)
{
	long	time_star;
	int		time_courr;

	time_star = get_time_ms();
	time_courr = get_time_ms() - time_star;
	while (time_courr < time)
	{
		pthread_mutex_lock(&philo->arg->detach);
		if (philo->arg->loop == 0)
		{
			pthread_mutex_unlock(&philo->arg->detach);
			break ;
		}
		pthread_mutex_unlock(&philo->arg->detach);
		usleep(100);
		time_courr = get_time_ms() - time_star;
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	print_message(philo, "eating");
	ft_usleep(philo->arg->t_eat, philo);
	pthread_mutex_lock(&philo->arg->meal_lock);
	philo->last_meal = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->arg->meal_lock);
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "sleeping");
	ft_usleep(philo->arg->t_sleep, philo);
}

void	thinking(t_philo *philo)
{
	print_message(philo, "thinking");
}
