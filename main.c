/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:44:54 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/23 19:53:53 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_philo *philo)
{
	int		i;
	t_rules	*rules;

	i = 0;
	rules = philo->rules;
	rules->forks = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	if (!rules->forks)
		return ;
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return ;
		i++;
	}
	if (pthread_mutex_init(&rules->write_lock, NULL) != 0)
		return ;
	rules->someone_died = 0;
	i = 0;
	while (i < philo->nb_philo)
	{
		philo->id = i + 1;
		philo->meals_eaten = 0;
		philo->last_meal = 0;
		philo->rules = rules;
		philo->left_fork = &rules->forks[i];
		philo->right_fork = &rules->forks[(i + 1) % philo->nb_philo];
		i++;
	}
}

void loop_init(t_rules *arg)
{
	int	i;

	i = 0;
	while (i < arg->nb_philo)
	{
		arg->philo->id = 0;
		arg->philo->meals_eaten = 0;
		arg->philo->last_meal = 0;
		arg->philo->rules = rules;
		arg->philo->left_fork = &rules->forks[i];
		arg->philo->right_fork = &rules->forks[(i + 1) % philo->nb_philo];
	}
	
}

void init(t_rules *arg)
{
	int		i;
	
	i = 0;
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->nb_philo);
	if (!arg->forks)
		return ;
	while (i < arg->nb_philo)
	{
		if (pthread_mutex_init(&arg->forks[i], NULL) != 0)
			return ;
		i++;
	}
	
	
	
}

int main(int ac, char **av)
{
	t_rules	*arg;

	arg = malloc(sizeof(t_rules));
	memset(arg, 0, sizeof(t_rules));
	parsing(av, ac, arg);
	init(arg);
	// free(arg->r);
	free(arg);
}
