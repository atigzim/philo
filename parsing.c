#include "philo.h"
void parsing(char **av, int ac, t_philo *philo)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	philo->rules = malloc(sizeof(t_rules));
	if (ac - 1 > 5 || ac -1 < 4)
	{
		write(2, "ERROR\n", 6);
		free(philo);
		exit(1);
	}
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+')
				j++;
			if (ft_isdigit(av[i][j]) == 0)
			{
				write(2, "ERROR\n", 6);
				free(philo);
				exit(1);
			}
			j++;
		}
		i++;
	}
	philo->rules->nb_philo = ft_atoi(av[1], philo->rules);
	philo->rules->t_die = ft_atoi(av[2], philo->rules);
	philo->rules->t_eat = ft_atoi(av[3], philo->rules);
	philo->rules->t_sleep = ft_atoi(av[4], philo->rules);
	if(ac - 1 ==  5)
		philo->rules->must_eat = ft_atoi(av[5], philo->rules);
}