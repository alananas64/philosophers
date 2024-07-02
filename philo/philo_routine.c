#include "philo.h"

void	take_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->info->p_id;
	right = (philo->info->p_id + 1) % philo->num_p;
	pthread_mutex_lock(&philo->forks[left]);
	printf ("<<<HERE>>>\n");
	printf ("{%i} has taken the left fork\n", philo->info->p_id);
	// log_action(philo->info->p_id, "has taken the left fork");
	pthread_mutex_lock(&philo->forks[right]);
	printf ("{%i} has taken the right fork\n", philo->info->p_id);
	// log_action(philo->info->p_id, "has taken the right fork");
}

void	put_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->info->p_id;
	right = (philo->info->p_id + 1) % philo->num_p;
	pthread_mutex_unlock(&philo->forks[left]);
	pthread_mutex_unlock(&philo->forks[right]);
}

int	check_starvation(t_philo *philo)
{
	// long	n_time;
	// int		flag;

	// flag = 0;
	// ft_mutex(philo, 1);
	// if (philo->info->philo_dead)
	// 	flag = 1;
	// else
	// {
	// 	n_time = n_timestamp(&philo->life_t);
	// 	if ((n_time - philo->life) > (philo->info->time_to_die))
	// 	{
	// 		ft_mutex(philo, 0);
	// 		print_info(philo, 5);
	// 		ft_mutex(philo, 1);
	// 		philo->info->philo_dead = true;
	// 		flag = 1;
	// 	}
	// }
	// ft_mutex(philo, 0);
	// return (flag);
	return (printf("here\n"), 0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	int i = 10;
	while (--i)
	{
		printf ("{%i} is thinking\n", philo->info->p_id);
		take_forks(philo);
		printf ("{%i} is eating\n", philo->info->p_id);
		usleep(philo->info->time_to_eat);
		put_forks(philo);
		printf ("{%i} is sleeping\n", philo->info->p_id);
		usleep(philo->info->time_to_sleep);
		if (check_starvation(philo)) // 
		{
			log_action(philo->info->p_id, "is dead");
			break ;
		}
	}
	return (NULL);
}
