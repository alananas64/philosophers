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
