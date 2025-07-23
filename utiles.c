/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:45:12 by atigzim           #+#    #+#             */
/*   Updated: 2025/07/23 05:18:22 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || c == 32)
		return (1);
	return (0);
}

void write_err(t_rules *philo)
{
	write(2, "ERROR\n", 6);
	free(philo);
	exit(1);
}

int	ft_atoi(const char *str, t_rules *philo)
{
	int (i), (j);
	long	nb;

	if(!str)
		return (0);
	i = 0;
	j = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		if (nb < 0 || nb > 2147483647)
			write_err(philo);
		i++;
	}
	if(nb == 0)
		write_err(philo);
	return ((int)(nb * j));
}
