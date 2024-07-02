#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->lfork);
	printf ("{%i} has taken the left fork\n", philo->info->p_id);
	// log_action(philo->info->p_id, "has taken the left fork");
	pthread_mutex_lock(&philo->info->rfork);
	printf ("{%i} has taken the right fork\n", philo->info->p_id);
	// log_action(philo->info->p_id, "has taken the right fork");
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->lfork);
	pthread_mutex_unlock(&philo->info->rfork);
}

// int	check_starvation(t_philo *philo)
// {
// 	// struct timeval	starvation;
// 	int	starvation;

// 	// starvation = gettimeofday(, NULL);
// 	if (philo->info->time_to_die >= (philo->info->last_meal))
// 		return (0);
// 	return (1);
// }

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	int i = 0;
	while (1 && ++i)
	{
		if (!philo[i].info)
		{
			printf ("<<<<<<here>>>>>>1\n");
			// exit (100);
		}
		printf ("{%i} is thinking\n", philo->info[i].p_id);
		// take_forks(philo);
		// printf ("{%i} is eating\n", philo->info->p_id);
		// usleep(philo->info->time_to_eat);
		// put_forks(philo);
		// printf ("{%i} is sleeping\n", philo->info->p_id);
		// usleep(philo->info->time_to_sleep);
		// if (check_starvation(philo)) //
		// {
		// 	log_action(philo->info->p_id, "is dead");
		// 	break ;
		// }
	}
	return (NULL);
}
