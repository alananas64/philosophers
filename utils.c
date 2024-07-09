/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:32:26 by nosman            #+#    #+#             */
/*   Updated: 2024/07/08 15:00:05 by nosman           ###   ########.fr       */
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


// i put the 2 upcoming functions in parsing file


// static int	handle_sign(const char *str, int *i)
// {
// 	int	sign;

// 	sign = 1;
// 	if (str[*i] == '-' || str[*i] == '+')
// 	{
// 		if (str[*i] == '-')
// 		{
// 			sign = -1;
// 		}
// 		(*i)++;
// 	}
// 	return (sign);
// }

// long long int	ft_atoll(const char *str)
// {
// 	int				i;
// 	int				sign;
// 	long long int	res;
// 	int				digit;

// 	i = 0;
// 	res = 0;
// 	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
// 		i++;
// 	sign = handle_sign(str, &i);
// 	while (ft_isdigit(str[i]))
// 	{
// 		digit = str[i] - '0';
// 		if ((res > (9223372036854775807 - digit) / 10) && sign == 1)
// 			return ((long long int)INT_MAX + 1);
// 		else if ((res > (9223372036854775807 - digit) / 10) && sign == -1)
// 			return ((long long int)INT_MAX + 1);
// 		res = (res * 10) + digit;
// 		i++;
// 	}
// 	return ((int) sign * res);
// }

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
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
