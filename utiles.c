#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	nb;

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
		i++;
	}
	return (nb * j);
}
