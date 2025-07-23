/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:44:54 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/24 00:37:12 by atigzim          ###   ########.fr       */
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
	printf("%ld\n", get_time_ms());
	free(arg);
}
