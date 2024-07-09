/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:31:50 by nosman            #+#    #+#             */
/*   Updated: 2024/07/08 14:36:07 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	create_threads(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	data->start_time = get_time();
// 	while (i < data->num_of_philo)
// 	{
// 		pthread_create(&data->philo[i].thread_id,
// 			NULL, &philo_routine, (void *)&data->philo[i]);
// 		i++;
// 	}
// }

// void	join_threads(t_data *data)
// {
// 	int	j;

// 	j = -1;
// 	while (++j < data->num_of_philo)
// 	{
// 		if (pthread_join(data->philo[j].thread_id, 0) != 0)
// 		{
// 			printf("Error: pthread_join error\n");
// 			return ;
// 		}
// 	}
// }

int	main(int ac, char **av)
{
	t_data	data;
	int		philo_dead_id;

	// if (arg_num(ac) || args_all_num(av))
	// 	return (1);
	if (parse(ac, av) == -1)
		return (-1);
	if (init_struct(&data, av) == -1)
		return (write(2, "Invalid argument\n", 17), 1);
		// return (ft_putstr_fd("Invalid argument\n", 2), 1);
	create_threads(&data);
	if (data.num_of_philo == 1)
		one_philo_case(data.philo);
	else
	{
		philo_dead_id = begin_monitoring(&data); // if non zero  he is dead
		join_threads(&data);
		if (philo_dead_id)
		{
			pthread_mutex_lock(&data.mutex_print);
			printf("\033[0;31m%lu %d died \033[0m\n", get_time()
				- data.philo->data->start_time, philo_dead_id);
			pthread_mutex_unlock(&data.mutex_print);
		}
	}
	close_up(&data);
	// while (1) ;
	return (0);
}
