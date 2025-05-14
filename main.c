#include "philo.h"

void parsing(char **av, int ac)
{
	int	i;
	i = 0;
	(void) av;
	if(ac - 1 > 5 || ac -1 < 4)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	while(av[i])
	{
		ft_atoi(av[i]);
		i++;
	}
	
}
int main(int ac, char **av)
{
	parsing(av, ac);
}