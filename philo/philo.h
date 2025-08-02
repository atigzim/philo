/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:14:18 by atigzim           #+#    #+#             */
/*   Updated: 2025/08/02 13:30:06 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	long			start_time;
	struct s_rules	*arg;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct s_rules
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	t_philo			*philo;
	pthread_mutex_t	someone_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	death;
}					t_rules;

 //   -----------------  parsing of  my programme -----------------  //
//   ------------------------------------------------------------   //  

void				parsing(char **av, int ac, t_rules *philo);
int					ft_atoi(const char *str, t_rules *philo, long nb);
int					ft_isdigit(int c);
void				write_err(t_rules *philo);

 //  -----------------  init_all -----------------------------  //
//   ---------------------------------------------------------  //

void				init_all(t_rules *arg);
long				get_time_ms(void);
void				print_message(t_philo *philo, char *str);

 //   -----------------  routine of  my philo -----------------  //
//   ---------------------------------------------------------  //
void	*routine(void *arg);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

#endif