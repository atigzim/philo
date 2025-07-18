#include "philo.h"

void *my_routine()
{ 
	t_philo *philo;
	
	if (philo.)
} 
void creat_therad (t_philo *phelo)
{
	int i;

	i = 0;
	while (i < phelo->rules->nb_philo)
	{
		if(pthread_create(phelo->thread,NULL, my_routine,phelo) != 0)
			perror("errore create");
		i++;
	}
	
}
void init(t_philo *fork)
{
	int	i;
	t_rules *rules;

	i = 0;
	rules = fork->rules;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	if(!rules->forks)
		return ;
	while (i < rules->nb_philo)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return;
		i++;
	}
	if (pthread_mutex_init(&rules->write_lock, NULL) != 0)
		return;
	rules->someone_died = 0;

	i = 0;
	while (i < rules->nb_philo)
	{
		fork->id =i ;
		fork->meals_eaten = 0;
		fork->last_meal = 0;
		fork->rules = rules;
		fork->left_fork = &rules->forks[i];
		fork->right_fork = &rules->forks[(i + 1) % rules->nb_philo];
		i++;
	}
	
}
int main(int ac, char **av)
{
	t_philo *philo;

	philo = NULL;
	philo = malloc(sizeof(t_philo));
	memset(philo, 0, sizeof(t_philo));
	parsing(av, ac, philo);
	init(philo);
	free(philo->rules);
	free(philo);
}