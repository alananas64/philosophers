#ifndef PHILO_H
# define PHILO_H

typedef struct s_info
{
	int	p_id;
	// int	num_p;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_info;

typedef struct s_philo
{
	int		num_p;
	int		number_of_times_each_philosopher_must_eat;
	t_info	info;
}	t_philo;

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


// ----- Parsing -----
int			parse(int arc, char **arv);
long long	ft_atoll(const char *str);
int			check_args(char **arv, int arc);

// ----- Initialize_philo -----
void	philo_init(char **arv);

#endif
