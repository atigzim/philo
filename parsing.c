/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:44:43 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/23 18:48:30 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void parsing(char **av, int ac, t_rules *arg)
{
	int (i), (j);
	i = 1;
	j = 0;
	if (ac - 1 > 5 || ac -1 < 4)
		write_err(arg);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+')
				j++;
			if (ft_isdigit(av[i][j]) == 0)
				write_err(arg);
			j++;
		}
		i++;
	}
	arg->nb_philo = ft_atoi(av[1], arg);
	arg->t_die = ft_atoi(av[2], arg);
	arg->t_eat = ft_atoi(av[3], arg);
	arg->t_sleep = ft_atoi(av[4], arg);
	if(ac - 1 ==  5)
		arg->must_eat = ft_atoi(av[5], arg);
}
