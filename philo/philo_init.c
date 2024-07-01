#include "philo.h"

static void	philo_mutex_intit(t_philo *philo, t_philo_info *info, int i)
{
	if ((pthread_mutex_init(&info->forks[i], NULL) != 0)
		|| (pthread_mutex_init(&info->write_lock, NULL) != 0)
		|| (pthread_mutex_init(&info->dead_lock, NULL) != 0))
		(perror("pthread_mutex_init"), exit(1));
	info->meal_lock = malloc(sizeof(pthread_mutex_t) * info->num_p);
	if (!info->meal_lock)
		(perror("malloc"), exit(1));
	i = -1;
	while (++i < info->num_p)
	{
		if (pthread_mutex_init(&info->meal_lock[i], NULL) != 0)
			(perror("pthread_mutex_init"), exit(1));
	}
	while (++i < info->num_p)
	{
		philo[i].p_id = i;
		philo[i].info = &info; // debatable
		philo[i].meals_eaten = 0;
		philo[i].last_meal = 0;
		if ((pthread_mutex_init(&philo[i].lock, NULL) != 0)
			|| (pthread_mutex_init(&philo[i].rlock, NULL) != 0)
			|| (pthread_mutex_init(&philo[i].dead_lock, NULL) != 0)
			|| (pthread_mutex_init(&philo[i].write_lock, NULL) != 0))
			(perror("pthread_mutex_init"), exit(1));
	}
}

void	philo_init(t_philo *philo, int argc, char **argv)
{
	t_philo_info	*info;
	int				i;

	info = malloc(sizeof(t_philo_info));
	if (!info)
		(perror("malloc"), exit(1));
	info->num_p = atoi(argv[1]);
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	info->times_each_philo_must_eat = -1;
	if (argc == 6)
		info->times_each_philo_must_eat = atoi(argv[5]);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_p);
	if (!info->forks)
		(perror("malloc"), exit(1));
	i = -1;
	while (++i < info->num_p)
		philo_mutex_intit(philo, info, i);
}
