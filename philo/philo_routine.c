#include "philo.h"

void	take_forks(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->info->lfork);
	printf ("\033[1;90m{%i} has taken the left fork\n", philo->info[i].p_id);
	// log_action(philo->info->p_id, "has taken the left fork");
	pthread_mutex_lock(&philo->info->rfork);
	printf ("\033[1;90m{%i} has taken the right fork\n", philo->info[i].p_id);
	// log_action(philo->info->p_id, "has taken the right fork");
}

void	put_forks(t_philo *philo, int i)
{
	pthread_mutex_unlock(&philo->info->lfork);
	printf ("\033[1;36m{%i} has kept the left fork\n", philo->info[i].p_id);
	pthread_mutex_unlock(&philo->info->rfork);
	printf ("\033[1;36m{%i} has kept the right fork\n", philo->info[i].p_id);
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

// lastmeal
void	*routine(void *arg)
{
	t_philo	*philo;
	int i = 0;

	philo = (t_philo *)arg;
	// while (--philo->eating_times >= 0)
	while (1)
	{
		if (++i > philo->num_p)
			i = 1;
		printf ("\033[1;32m{%i} is thinking\n", philo->info[i].p_id); // green
		take_forks(philo, philo->info[i].p_id);
		printf ("\033[1;33m{%i} is eating\n", philo->info[i].p_id); // yellow
		usleep(philo->info->time_to_eat);
		put_forks(philo, philo->info[i].p_id);
		printf ("\033[1;34m{%i} is sleeping\n", philo->info[i].p_id); // blue
		usleep(philo->info->time_to_sleep);
		// if (check_starvation(philo)) //
		// {
		// 	log_action(philo->info[i].p_id, "is dead");
		// 	break ;
		// }
	}
	return (NULL);
}
