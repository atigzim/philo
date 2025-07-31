#include "philo.h"

int main(int ac , char **av)
{
	t_rules *arg;

	arg = malloc(sizeof(t_rules));
	memset(arg, 0, sizeof(t_rules));
	parsing(av, ac, arg);
}