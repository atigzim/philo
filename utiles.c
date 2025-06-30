#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || c == 32)
		return (1);
	return (0);
}

long	ft_atoi(const char *str, t_rules *philo)
{
	int	i;
	int	j;
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
		if (nb <= 0 || nb > 2147483647)
		{
			write(2, "ERROR\n", 6);
			free(philo);
			exit(1);
		}
		i++;
	}
	return (nb * j);
}
