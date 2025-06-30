#include "philo.h"


void init(t_philo *fork)
{
	int	i;
	t_rules *rules;

	rules = fork->rules;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	if(!rules->forks)
		return ;
	while (i < rules->nb_philo)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&rules->write_lock, NULL) != 0)
		return (0);
	rules->someone_died = 0;

	i = 0;
	while (i < rules->nb_philo)
	{
		fork->id =i ;
		fork->meals_eaten = 0;
		fork->last_meal = ;
		fork->rules = rules;
		fork->left_fork = &rules->forks[i];
		fork
		
	}
	
}
int main(int ac, char **av)
{
	t_philo *philo;

	philo = NULL;
	philo = malloc(sizeof(t_philo));
	memset(philo, 0, sizeof(t_philo));
	parsing(av, ac, philo);
	free(philo->rules);
	free(philo);
}