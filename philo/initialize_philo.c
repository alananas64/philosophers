#include "philo.h"

int	philo_mutex_init(t_philo *philo, t_philo_info *info, int ac, char *av)
{
	int	i;

	i = 0;
	while (++i <= philo->num_p)
	{
		info[i].meals_eaten = 0;
		info[i].last_meal = 0;
		info->time_to_die = atoi(av[2]);
		info->time_to_eat = atoi(av[3]);
		info->time_to_sleep = atoi(av[4]);
		philo->times_to_eat = -1;
		if (ac == 6)
			philo->times_to_eat = atoi(av[5]);
		info[i].write_lock = &philo->write_lock;
		info[i].dead_lock = &philo->dead_lock;
		info[i].meal_lock = &philo->meal_lock;
		if ((pthread_mutex_init(&philo->forks[i], NULL) != 0)
			|| (pthread_mutex_init(&info[i].rfork, NULL) != 0)
			|| (pthread_mutex_init(&info[i].lfork, NULL) != 0))
			return ((printf("pthread_mutex_init"), -1));
		info[i].rfork = philo->forks[i]; // check header
		info[i].lfork = philo->forks[(i + 1) % philo->num_p]; // check header
	}
}

int	philo_init(t_philo *philo, int ac, char **av)
{
	t_philo_info	*info;

	philo->num_p = atoi(av[1]);
	info = malloc(sizeof(t_philo_info) * philo->num_p);
	if (!info)
		return (printf("malloc"), -1);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_p);
	if (!philo->forks)
		return (printf("malloc"), -1);
	philo->info = info;
	if ((pthread_mutex_init(&philo->write_lock, NULL) != 0)
		|| (pthread_mutex_init(&philo->meal_lock, NULL) != 0)
		|| (pthread_mutex_init(&philo->dead_lock, NULL) != 0)
		|| (philo_mutex_init(philo, info, av, ac)))
		return ((printf("pthread_mutex_init"), -1));
	return (0);
}
