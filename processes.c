/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:41:52 by nosman            #+#    #+#             */
/*   Updated: 2024/07/08 16:41:55 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * checks if a philosopher can pick up both their left and right forks to eat
 * If both forks are available, it marks them as being used by the philosopher and returns 1.
 * If either fork is not available, it returns 0
*/
int	is_fork_available(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (*philo->l_fork && *philo->l_fork != philo->id)
		pthread_mutex_unlock(philo->left_fork);
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork);
	if (*philo->r_fork && *philo->r_fork != philo->id)
	{
		*philo->r_fork = philo->id;
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	return (1);
}
/**
 * allows a philosopher to take both their left and right forks if they are available
 *  and prints messages to indicate that the forks have been taken.
 * If the forks are not available, it returns an error code (1)
*/
int	philo_takes_forks(t_philo *philo)
{
	if (is_fork_available(philo))
	{
		pthread_mutex_lock(philo->left_fork);
		*philo->l_fork = 0;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		*philo->r_fork = 0;
		pthread_mutex_unlock(philo->right_fork);
	}
	else
		return (1);
	print_message("\033[1;90mhas taken a fork\033[0m", philo);
	print_message("\033[1;90mhas taken a fork\033[0m", philo);
	return (0);
}

int	philo_is_eating(t_philo *philo)
{
	print_message("\033[1;35m\033[0m\033[1;35mis eating\033[0m", philo);
	pthread_mutex_lock(&philo->data->mutex_dead);
	philo->time_to_die = (get_time() - philo->data->start_time)
		+ philo->data->time_to_die;
	pthread_mutex_unlock(&philo->data->mutex_dead);
	if (is_philo_dead(philo->data))
		return (drop_forks(philo), 0);
	if (!ft_sleep(philo->data->time_to_eat, philo))
		return (drop_forks(philo), 0);
	pthread_mutex_lock(&philo->data->mutex_meals);
	if (philo->data->meals_counter != -1)
		philo->data->meals_counter++;
	pthread_mutex_unlock(&philo->data->mutex_meals);
	drop_forks(philo);
	return (1);
}

int	philo_is_sleeping(t_philo *philo)
{
	if (!is_philo_dead(philo->data))
	{
		print_message("\033[1;34mis sleeping\033[0m", philo);
		if (!ft_sleep(philo->data->time_to_sleep, philo))
			return (0);//if the sleep is interrupted or the philosopher is dead
		return (1); // if the sleep is successful
	}
	else
		return (0);
}

int	philo_is_thinking(t_philo *philo)
{
	if (!is_philo_dead(philo->data))
	{
		print_message("\033[1;96mis thinking\033[0m", philo);
		return (1);
	}
	else
		return (0);
}
