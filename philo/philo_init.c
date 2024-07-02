#include "philo.h"

void	philo_mutex_init(t_philo *philo, t_philo_info *info, int i)
{
	if ((pthread_mutex_init(&info->forks[i], NULL) != 0)
		|| (pthread_mutex_init(&info->write_lock, NULL) != 0)
		|| (pthread_mutex_init(&info->dead_lock, NULL) != 0))
		printf("pthread_mutex_init");
		// return ((printf("pthread_mutex_init"), i));
	info->meal_lock = malloc(sizeof(pthread_mutex_t) * info->num_p);
	if (!info->meal_lock)
		printf("pthread_mutex_init");
		// return ((printf("malloc"), i));
	i = -1;
	while (++i < info->num_p)
	{
		if (pthread_mutex_init(&info->meal_lock[i], NULL) != 0)
			printf("pthread_mutex_init");
			// return ((printf("pthread_mutex_init"), i));
	}
	while (++i < info->num_p)
	{
		philo[i].p_id = i;
		philo[i].info = info; // debatable
		philo[i].meals_eaten = 0;
		philo[i].last_meal = 0;
		if ((pthread_mutex_init(&philo[i].lock, NULL) != 0)
			|| (pthread_mutex_init(&philo[i].rlock, NULL) != 0)
			|| (pthread_mutex_init(&philo[i].dead_lock, NULL) != 0)
			|| (pthread_mutex_init(&philo[i].write_lock, NULL) != 0))
			printf("pthread_mutex_init");
			// return ((printf("pthread_mutex_init"), i));
	}
}

// void	philo_data(t_program *program, t_params *params)
// {
// 	t_philo	*philos;
// 	int		i;

// 	philos = program->philos;
// 	i = 0;
// 	while (i < params->philo_count)
// 	{
// 		philos[i].id = i + 1;
// 		philos[i].params = params;
// 		philos[i].eating = 0;
// 		philos[i].meals_eaten = 0;
// 		philos[i].last_meal = get_current();
// 		philos[i].start_time = get_current();
// 		philos[i].dead = &program->dead_flag;
// 		philos[i].dead_lock = &program->dead_lock;
// 		philos[i].meal_lock = &program->meal_lock;
// 		philos[i].write_lock = &program->write_lock;
// 		philos[i].l_fork = &program->forks[i];
// 		if (i == 0)
// 			philos[i].r_fork = &program->forks[params->philo_count - 1];
// 		else
// 			philos[i].r_fork = &program->forks[(i - 1)];
// 		i++;
// 	}
// }

int	philo_init(t_philo *philo, int argc, char **argv)
{
	t_philo_info	*info;
	int				i;

	info = malloc(sizeof(t_philo_info));
	if (!info)
		return (perror("malloc"), 1);
	info->num_p = atoi(argv[1]);
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	info->times_each_philo_must_eat = -1;
	if (argc == 6)
		info->times_each_philo_must_eat = atoi(argv[5]);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_p);
	if (!info->forks)
		return (printf("malloc"), 1);
	i = -1;
	while (++i < info->num_p)
		philo_mutex_init(philo, info, i);
	return (i);
}
