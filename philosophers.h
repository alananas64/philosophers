/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:32:33 by nosman            #+#    #+#             */
/*   Updated: 2024/07/08 14:40:27 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	int						id;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	int						*r_fork;
	int						*l_fork;
	int						num_of_philo;
	unsigned long int		time_to_die;
	unsigned long int		time_to_eat;
	unsigned long int		time_to_sleep;
	pthread_t				thread_id;
	struct s_data			*data;
}				t_philo;

typedef struct s_data
{
	int						num_of_philo;
	unsigned long int		time_to_die;
	unsigned long int		time_to_eat;
	unsigned long int		time_to_sleep;
	int						num_of_meals;
	int						meals_counter;
	int						philo_dead;
	unsigned long int		start_time;
	int						*forks_taken;
	pthread_mutex_t			*forks;
	pthread_mutex_t			mutex_dead;
	pthread_mutex_t			mutex_print;
	pthread_mutex_t			mutex_meals;
	t_philo					*philo;
}				t_data;

//************************ Libft ************************//
// long long int		ft_atoi_l(const char *str);
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);

//************************ Philosophers ************************//
// int					args_all_num(char **av);
// int					arg_num(int ac);
int	parse(int arc, char **arv);
int	check_args(char **arv, int arc);
long long	ft_atoll(const char *str);
int					init_struct(t_data *data, char **av);
void				create_threads(t_data *data);
int					begin_monitoring(void *arg);
int					philo_takes_forks(t_philo *philo);
int					philo_is_eating(t_philo *philo);
int					philo_is_sleeping(t_philo *philo);
int					philo_is_thinking(t_philo *philo);
void				print_message(char *str, t_philo *philo);
void				*philo_routine(void *arguments);
void				join_threads(t_data *data);
unsigned long int	get_time(void);
void				is_max_eat(t_philo *philo);
int					ft_sleep(unsigned long int time, t_philo *philo);
int					check_last_meal(t_philo *philo);
void				one_philo_case(t_philo *philo);
int					check_if_one_is_dead(t_data *data);
void				drop_forks(t_philo *philo);
int					is_philo_dead(t_data *data);
void				close_up(t_data *data);

#endif
