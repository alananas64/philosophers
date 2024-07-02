#include "philo.h"

void	destroy_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i)
		pthread_mutex_destroy(philo[i]->info.thread);
}

// void	print_philo(t_philo *philo, t_philo_info *info)
// {
// 	printf ("{%i}\n", philo->times_to_eat);
// 	printf ("{%i}\n", info->num_p);
// 	int i = -1;
// 	while (++i < info->num_p)
// 	{
// 		printf ("{%i}\n", philo[i].info->time_to_die);
// 		printf ("{%i}\n", philo[i].info->time_to_eat);
// 		printf ("{%i}\n", philo[i].info->time_to_sleep);
// 	}
// }

int	main(int ac, char **av)
{
	int				i;
	t_philo			*philo;

	if (parse(ac, av) == -1)
		return (-1);
	philo = malloc(sizeof(t_philo) * atoi(av[1]));
	if (!philo)
		return (1);
	philo_init(philo, ac, av);
	// print_philo(philo, philo->info); // debugging
	i = 0;
	while (++i <= philo->num_p)
	{
		philo->info[i].p_id = i;
		if (pthread_create(&philo->info[i].thread, NULL, routine, &philo[i]))
			return (i);
		// philo->info[i] = info;
	}
	i = 0;
	while (++i <= philo->num_p)
		if (pthread_join(philo->info[i].thread, NULL))
			return (i);
	// destroy_philo(philo);
	return (free(&philo->info), free(philo), 0);
}
