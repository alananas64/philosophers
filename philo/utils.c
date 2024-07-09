/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:32:26 by nosman            #+#    #+#             */
/*   Updated: 2024/07/09 10:30:16 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	close_up(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		if (pthread_mutex_lock(&data->forks[i]) == 0)
			pthread_mutex_unlock(&data->forks[i]);
		else
			pthread_mutex_unlock(&data->forks[i]);
	}
	i = -1;
	while (++i < data->num_of_philo)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks_taken);
	free(data->forks);
	free(data->philo);
}

unsigned long int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_sleep(unsigned long int time, t_philo *philo)
{
	unsigned long	start;

	// pthread_mutex_lock(&philo->data->mutex_dead);
	start = get_time();
	while ((get_time() - start) < time)
	{
		// pthread_mutex_unlock(&philo->data->mutex_dead);
		if (is_philo_dead(philo->data))
			return (0);
		usleep(100);
		// pthread_mutex_lock(&philo->data->mutex_dead);
	}
	// pthread_mutex_unlock(&philo->data->mutex_dead);
	return (1);
}
