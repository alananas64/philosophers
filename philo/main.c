// #include "philo.h"
#ifndef PHILO_H
# define PHILO_H

# define MAX_PHILO 200

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
// # include <bits/pthreadtypes.h>
# include <sys/time.h>

typedef struct s_info
{
    int num_p;
    int	time_to_die;
    int	time_to_eat;
    int	time_to_sleep;
    int times_each_philo_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo_info;

typedef struct s_philo
{
    pthread_t		thread;
    int             p_id;
	int             meals_eaten;
	long            last_meal;
    t_philo_info    info;
    pthread_mutex_t	lock;
    pthread_mutex_t	rlock;
    pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
}	t_philo;

int     parse(int arc, char **arv);
void    philo_init(t_philo *philo, int ac, char **arv);

#endif

static void	*routine(void *philo_info)
{
	t_philo	*philo;

	philo = (t_philo *)philo_info;
	while (philo->philo_info->num_of_philo == 1)
		return (handle_single_philo(philo, philo->philo_info->time_to_die));
	while (1)
	{
		if (is_philo_dead(philo) || !philo->times_to_eat)
			break ;
		lock_order(philo);
		pthread_mutex_lock(&philo->rlock);
		if (!(philo->fork) && !(philo->next->fork) && philo->times_to_eat
			&& !check_mirror_fork(philo))
			if (!philo_eat(philo))
				return (NULL);
		pthread_mutex_unlock(&philo->rlock);
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_unlock(&philo->next->lock);
		usleep(100);
	}
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->p_id;
	right = (philo->p_id + 1) % philo->info->num_p;
	pthread_mutex_lock(&philo->info->forks[left]);
	log_action(philo->p_id, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[right]);
	log_action(philo->p_id, "has taken a fork");
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

void	*philosopher_routine(void *arg)
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
		if (check_starvation(id))
		{
			log_death(id);
			break ;
		}
	}
	return (NULL);
}

int	parse(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf ("invalid ammount of arguments\n"), -1);
	if (check_args(av, ac) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	int				i;
	t_philo			*philo;
	t_philo_info	info;

	if (parse(ac, av) == -1)
		return (-1);
	philo = malloc(sizeof(t_philo) * atoi(av[1]));
	if (!philo)
		return (1);
	philo_init(philo, ac, av);
	i = -1;
	while (++i < info.num_p)
	{
		pthread_create(&philo[i].thread, NULL, philosopher_routine, &philo[i]);
		philo[i].p_id = i;
		philo[i].info = &info;
	}
	i = -1;
	while (++i < info.num_p)
		pthread_join(philo[i].thread, NULL);
	destroy_philo_threads();
	free(&philo->info);
	free(philo);
	return (0);
}