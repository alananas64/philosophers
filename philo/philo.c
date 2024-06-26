#include "philo.h"

int	main(int arc, char **arv)
{
	if (parse(arc, arv) == -1)
	{
		printf("u got a problem in parsing");
		return (-1);
	}
	philo_init(arv);
	printf("\nphilo\n");
	return (0);
}

/**
 * number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * number_of_times_each_philosopher_must_eat
*/
