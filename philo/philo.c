#include "philo.h"

void	destroy_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i)
		pthread_mutex_destroy(philo[i].thread);
}

void	print_philo(t_philo *philo, t_philo_info *info)
{
	printf ("{%i}\n", info->num_p);
	printf ("{%i}\n", info->time_to_die);
	printf ("{%i}\n", info->time_to_eat);
	printf ("{%i}\n", info->time_to_sleep);
	printf ("{%i}\n", info->times_each_philo_must_eat);
}

int	main(int ac, char **av)
{
	int				i;
	t_philo			*philo;
	t_philo_info	*info;

	if (parse(ac, av) == -1)
		return (-1);
	philo = malloc(sizeof(t_philo) * atoi(av[1]));
	if (!philo)
		return (1);
	philo_init(philo, ac, av);
	i = -1;
	while (++i < info->num_p)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (i);
		philo[i].p_id = i;
		philo[i].info = &info;
		if (pthread_join(philo[i].thread, NULL))
			return (i);
	}
	while (++i < info->num_p)
		if (pthread_join(philo[i].thread, NULL))
			return (i);
	destroy_philo(philo);
	(free(&philo->info), free(philo));
	return (0);
}
