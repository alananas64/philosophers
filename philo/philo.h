/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_PHILO 200
# define MIN_PHILO 1
# define LOG_ACTION 1

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
// # include <bits/pthreadtypes.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo_info
{
    int				p_id;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
	int				*philo_dead;
	long			last_meal;
	int				meals_eaten;
    pthread_t		thread;
    pthread_mutex_t	rfork;
    pthread_mutex_t	lfork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo_info;

typedef struct s_philo
{
    int 			num_p;
	int				philo_dead;
    int				eating_times;
    t_philo_info	*info;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
}	t_philo;

/* *********************** parse functions ********************************** */
int		parse(int arc, char **arv);

/* *********************** initialize functions ***************************** */
int		philo_init(t_philo *philo, int argc, char **argv);
int		philo_mutex_init(t_philo *philo, t_philo_info *info, int ac, char **av);

/* *********************** routine functions ******************************** */
void	*routine(void *arg);
void	log_action(int id, char *msg);

#endif

/*
 * Program Structure: ./philo 2 800 200 200 5
 *
 * Mandatory Part:
 * Each philosopher is a thread.
 * Use mutexes to manage fork access.
 *
 * Bonus Part:
 * Philosophers are processes.
 * Use semaphores to manage fork availability.
 *
 * Simulation Rules:
 * Each philosopher alternates between eating, thinking, and sleeping.
 * Philosophers need two forks to eat.
 * Simulation parameters include number of philosophers, time to die, time to eat, and time to sleep.
 * Logging:
 *
 * Log state changes with timestamps (taking a fork, eating, sleeping, thinking, dying).
 * Ensure no data races and proper synchronization.
 * use flasg -fsanitize=thread -fsanitize=undefined
 *
 * Pseudocode
 * Initialization
 * Parse command-line arguments.
 * Initialize structures.
 * Create and initialize mutexes for forks.
 * Create philosopher threads.
 *
 * Setup Environment:
 * Parse Command-Line Arguments:
 *
 * function to parse the number of philosophers, times for eating, sleeping, and dying.
 * Initialize Resources:
 *
 * Initialize mutexes for forks.
 * Allocate memory for philosopher structures.
 * Thread/Process Creation:
 *
 * For the mandatory part, create threads for each philosopher.
 * For the bonus part, create processes for each philosopher.
 * Implement Philosopher Logic:
 *
 * Define the philosopher routine: thinking, taking forks, eating, putting forks, sleeping.
 * Ensure proper synchronization using mutexes/semaphores.
 * Logging:
 *
 * Implement logging for state changes with timestamps.
 * Testing and Debugging:
 *
 * $(NAME): $(OBJS)
 *     $(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread
 *
 * // Pseudocode
 * void philosopher_routine(int id)
 * {
 *     while (1)
 *     {
 *         think();
 *         take_forks(id);
 *         eat();
 *         put_forks(id);
 *         sleep();
 *         if (check_starvation(id))
 *         {
 *             log_death(id);
 *             break ;
 *         }
 *     }
 * }
 * */
