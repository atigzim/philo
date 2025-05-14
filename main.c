#include "philo.h"

void parsing(char **av, int ac, t_arg *philo)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if(ac - 1 > 5 || ac -1 < 4)
	{
		write(1, "ERROR\n", 6);
		free(philo);
		exit(1);
	}
	while(av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if(av[i][j] == '+')
				j++;
			if(ft_isdigit(av[i][j]) == 0)
			{
				write(1, "ERROR\n", 6);
				free(philo);
				exit(1);
			}
			j++;
		}
		i++;
	}
	philo->philo = ft_atoi(av[1],philo);
	philo->t_die = ft_atoi(av[2], philo);
	philo->t_eat = ft_atoi(av[3], philo);
	philo->t_sleep = ft_atoi(av[4], philo);
	if(ac - 1 ==  5)
		philo->t_p_eat = ft_atoi(av[5], philo);
}
int main(int ac, char **av)
{
	t_arg *philo;

	philo = malloc(sizeof(t_arg));
	parsing(av, ac, philo);
	free(philo);
}