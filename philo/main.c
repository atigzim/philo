/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:11:28 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/11 15:40:48 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	*arg;

	arg = malloc(sizeof(t_rules));
	memset(arg, 0, sizeof(t_rules));
	parsing(av, ac, arg);
	init_all(arg);
	if (arg->nb_philo == 1)
	{
		one_philo(arg);
		one_philo_t(arg->philo);
	}
	else
	{
		create_thread(arg);
		monitor(arg->philo);
		joun(arg);
	}
}
