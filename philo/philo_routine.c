#include "philo.h"

void	take_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->p_id;
	right = (philo->p_id + 1) % philo->info->num_p;
	pthread_mutex_lock(&philo->info->forks[left]);
	log_action(philo->p_id, "has taken left fork");
	pthread_mutex_lock(&philo->info->forks[right]);
	log_action(philo->p_id, "has taken right fork");
}

void	put_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->p_id;
	right = (philo->p_id + 1) % philo->info->num_p;
	pthread_mutex_unlock(&philo->info->forks[left]);
	pthread_mutex_unlock(&philo->info->forks[right]);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		log_action(philo->p_id, "is thinking");
		take_forks(philo);
		log_action(philo->p_id, "is eating");
		usleep(philo->info->time_to_eat * 1000);
		put_forks(philo);
		log_action(philo->p_id, "is sleeping");
		usleep(philo->info->time_to_sleep * 1000);
		if (check_starvation(philo->p_id))
		{
			log_death(philo->p_id);
			break ;
		}
	}
	return (NULL);
}
