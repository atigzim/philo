/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:44:43 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/23 02:42:58 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void parsing(char **av, int ac, t_philo *philo)
{
	int (i), (j);
	i = 1;
	j = 0;
	philo->rules = malloc(sizeof(t_rules));
	if (ac - 1 > 5 || ac -1 < 4)
		write_err(philo->rules);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+')
				j++;
			if (ft_isdigit(av[i][j]) == 0)
				write_err(philo->rules);
			j++;
		}
		i++;
	}
	philo->nb_philo = ft_atoi(av[1], philo->rules);
	philo->rules->t_die = ft_atoi(av[2], philo->rules);
	philo->rules->t_eat = ft_atoi(av[3], philo->rules);
	philo->rules->t_sleep = ft_atoi(av[4], philo->rules);
	if(ac - 1 ==  5)
		philo->rules->must_eat = ft_atoi(av[5], philo->rules);
}\
