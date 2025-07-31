#include "philo.h"
void *routine(void *arg)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		
	}
	
}
void create_thread(t_rules *arg)
{
	int i;
	t_philo *philo;

	i = 0;
	philo = arg->philo;
	while (i < arg->nb_philo)
	{
		philo[i].start_time = get_time_ms();
		if ((pthread_create(&philo[i].thread, NULL, routine, &philo[i])) != 0)
		{
			printf("Failed to create thread for philo %d\n", i + 1);
			return ;
		}
	}
	
}

int main(int ac , char **av)
{
	t_rules *arg;

	arg = malloc(sizeof(t_rules));
	memset(arg, 0, sizeof(t_rules));
	parsing(av, ac, arg);
	init_all(arg);
}