/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:14:25 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/07 18:32:23 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
	write(fd, " ", 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(long n, int fd)
{
	{
		if (n == -2147483648)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd('8', fd);
		}
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
		else if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else if (n <= 9)
		{
			ft_putchar_fd((n + '0'), fd);
		}
	}
}

void	print_message(t_philo *philo, char *str)
{
	if(check_loob(philo->arg))
	{
		pthread_mutex_lock(&philo->arg->write_lock);
		ft_putnbr_fd(get_time_ms() - philo->start_time, 1);
		write(1, " ", 1);
		ft_putnbr_fd(philo->id, 1);
		write(1, " ", 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
		pthread_mutex_unlock(&philo->arg->write_lock);	
	}
}

void print_isdied(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->arg->write_lock);
	ft_putnbr_fd(get_time_ms() - philo->start_time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	pthread_mutex_unlock(&philo->arg->write_lock);
}
