#include "philo.h"

// void	destroy_philo(t_philo *philo)
// {
// 	int	i;

// 	i = -1;
// 	while (++i)
// 		pthread_mutex_destroy(philo[i].info->thread);
// }

// void	print_philo(t_philo *philo)
// {
// 	printf ("eating_times {%i}\n", philo->eating_times);
// 	printf ("num_p {%i}\n", philo->num_p);
// 	int i = 0;
// 	while (++i < philo->num_p)
// 	{
// 		printf ("p_id {%i}\n", philo[i].info->p_id);
// 		printf ("time_to_die {%i}\n", philo[i].info->time_to_die);
// 		printf ("time_to_eat {%i}\n", philo[i].info->time_to_eat);
// 		printf ("time_to_sleep {%i}\n", philo[i].info->time_to_sleep);
// 		printf ("philo_dead {%i}\n", philo[i].philo_dead);
// 	}
// }

int	main(int ac, char **av)
{
	int				i;
	t_philo			*philo;

	i = 0;
	if (parse(ac, av) == -1)
		return (-1);
	philo = malloc(sizeof(t_philo) * atoi(av[1]));
	if (!philo)
		return (1);
	philo_init(philo, ac, av);
	// print_philo(philo); // debugging
	while (++i <= philo->num_p)
	{
		if (!philo->info)
		{
			printf ("<<<<<<philo init>>>\n");
			// exit (100);
		}
		// philo->info[i].p_id = i;
		if (pthread_create(&philo->info[i].thread, NULL, routine, (void *)&philo[i]))
			return (i);
		usleep(50);
	}
	i = 0;
	while (++i <= philo->num_p)
		if (pthread_join(philo->info[i].thread, NULL))
			return (i);
	// destroy_philo(philo);
	return (free(&philo->info), free(philo), 0);
}
