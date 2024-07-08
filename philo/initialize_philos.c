/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:02:39 by nosman            #+#    #+#             */
/*   Updated: 2024/07/08 14:05:44 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_sleep(unsigned long int time, t_philo *philo)
{
	unsigned long	start;

	pthread_mutex_lock(&philo->data->mutex_dead);
	start = get_time();
	while ((get_time() - start) < time)
	{
		pthread_mutex_unlock(&philo->data->mutex_dead);
		if (is_philo_dead(philo->data))
			return (0);
		usleep(100);
		pthread_mutex_lock(&philo->data->mutex_dead);
	}
	pthread_mutex_unlock(&philo->data->mutex_dead);
	return (1);
}
/**
 * upcoming three functions are for initialize the philo and the mutex
*/
int	initialize_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].l_fork = &data->forks_taken[i];
		data->philo[i].left_fork = &data->forks[i];
		if (data->philo[i].id == data->num_of_philo)
		{
			data->philo[i].r_fork = &data->forks_taken[0];
			data->philo[i].right_fork = &data->forks[0];
		}
		else
		{
			data->philo[i].r_fork = &data->forks_taken[i + 1];
			data->philo[i].right_fork = &data->forks[i + 1];
		}
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].data = data;
		// data->philo[i].num_of_philo = data->num_of_philo; // i do not think it is neccessary
	}
	return (0);
}

int	create_mutex(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!data->forks)
		return (-1);
	data->forks_taken = malloc(sizeof(int) * data->num_of_philo); //////////////////////////////
	if (!data->forks_taken)
		return (-1);
	data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
	if (!data->philo)
		return (-1);
	while (++i < data->num_of_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	while (++j < data->num_of_philo)
		data->forks_taken[j] = -1; // -1 means no forks are token yet
	pthread_mutex_init(&data->mutex_dead, NULL);//protect access to a variable that indicates whether a philosopher is dead.
	pthread_mutex_init(&data->mutex_meals, NULL);//protect access to a variable that counts the number of meals eaten by the philosophers
	pthread_mutex_init(&data->mutex_print, NULL);//protect access to a function that prints output, to ensure that only one thread can print at a time.
	return (0);
}

/**
 *  initializes the data structure that holds the parameters
*/
int	init_struct(t_data *data, char **av)
{
	data->num_of_philo = ft_atoll(av[1]);
	if ((data->num_of_philo <= 0) || (data->num_of_philo > 200)) // already handled in parsing
		return (-1);
	data->time_to_die = ft_atoll(av[2]);
	data->time_to_eat = ft_atoll(av[3]);
	data->time_to_sleep = ft_atoll(av[4]);
	if (av[5])
	{
		data->num_of_meals = ft_atoll(av[5]);
		if (data->num_of_meals <= 0) // i think this is already handled in parsing?if not it should be over there
			return (-1);
	}
	else
		data->num_of_meals = -1;
	data->philo_dead = 0;
	data->start_time = 0;
	data->meals_counter = 0;
	if (create_mutex(data) == -1 || initialize_philos(data)) // -1 or any nonzero is un error, zero is success
		return (-1);
	return (0);
}
