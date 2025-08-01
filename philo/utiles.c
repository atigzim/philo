#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || c == 32)
		return (1);
	return (0);
}

void	write_err(t_rules	*philo)
{
	write(2, "ERROR\n", 6);
	free(philo);
	exit(1);
}

long get_time_ms(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str, t_rules *philo)
{
	long	nb;

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
void print_message(int id, t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->arg->write_lock);
	ft_putnbr_fd(get_time_ms() - philo->start_time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(id, 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	// printf("%ld  %d  %s\n", get_time_ms() - philo->start_time, id, str);
	pthread_mutex_unlock(&philo->arg->write_lock);
}
