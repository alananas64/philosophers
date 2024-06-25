#include "philo.h"

void	philo_init(char **arv)
{
	int	i;
	t_philo	*philo;

	i = 1;
	philo = malloc(sizeof(t_philo));
	philo->num_p = ft_atoll(arv[i++]);
	philo->info.time_to_die = ft_atoll(arv[i++]);
	philo->info.time_to_eat = ft_atoll(arv[i++]);
	philo->info.time_to_sleep = ft_atoll(arv[i++]);
	philo->number_of_times_each_philosopher_must_eat = ft_atoll(arv[i++]);
	printf("philo->num_p{%i}\n", philo->num_p);
	printf("philo->info.time_to_die{%i}\n", philo->info.time_to_die);
	printf("philo->info.time_to_eat{%i}\n", philo->info.time_to_eat);
	printf("philo->info.time_to_sleep{%i}\n", philo->info.time_to_sleep);
	printf("philo->number_of_times_each_philosopher_must_eat{%i}\n", philo->number_of_times_each_philosopher_must_eat);
}

int	parse(int arc, char **arv)
{
	if (arc < 5 || arc > 6)
		return (printf ("invalid ammount of arguments\n"), -1);
	if(ft_isdigit(arv, arc) == -1)
		return (printf ("Only accept digits\n"), -1);
	return (0);
}
// 4 400 200 200

int	main(int arc, char **arv)
{
	if (parse(arc, arv) == -1)
	{
		printf("u got a problem in parsing");
		return (-1);
	}
	philo_init(arv);
	printf("\nphilo\n");
	return (0);
}

/**
 * number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * number_of_times_each_philosopher_must_eat
*/
