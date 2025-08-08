/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:14:22 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/08 20:33:07 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || c == 32)
		return (1);
	return (0);
}

void	write_err(t_rules *philo)
{
	write(2, "ERROR\n", 6);
	free(philo);
	exit(1);
}

long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str, t_rules *philo, long nb)
{
	int (i), (j);
	if (!str)
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
	if (nb == 0)
		write_err(philo);
	return ((int)(nb * j));
}

int	check_loob(t_rules *arg)
{
	int	j;

	pthread_mutex_lock(&arg->detach);
	j = arg->loop;
	pthread_mutex_unlock(&arg->detach);
	return (j);
}
