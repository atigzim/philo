/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:14:06 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/08 20:31:59 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	joun(t_rules *arg)
{
	int	i;

	i = 0;
	while (i < arg->nb_philo)
	{
		pthread_join(arg->philo[i].thread, NULL);
		i++;
	}
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

void	one_philo_t(t_philo *philo)
{
	if (pthread_create(&philo[0].thread, NULL, routine, &philo[0]) != 0)
	{
		printf("Failed to join thread for philo 1\n");
		return ;
	}
	if (pthread_join(philo[0].thread, NULL))
	{
		printf("Failed to join thread for philo 1\n");
		return ;
	}
}

void	one_philo(t_rules *arg)
{
	if (arg->nb_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(arg->t_die * 1000);
		printf("%d  1  is died", arg->t_die);
		joun(arg);
		free(arg->forks);
		free(arg->philo);
		free(arg);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_rules	*arg;

	arg = malloc(sizeof(t_rules));
	memset(arg, 0, sizeof(t_rules));
	parsing(av, ac, arg);
	init_all(arg);
	if (arg->nb_philo == 1)
	{
		one_philo_t(arg->philo);
		one_philo(arg);
	}
	create_thread(arg);
	joun(arg);
	free(arg->forks);
	free(arg->philo);
	free(arg);
}
