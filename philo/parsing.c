#include "philo.h"

long long	ft_atoll(const char *str)
{
	long		i;
	long		sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
		if (result * sign < 0 || result * sign > INT_MAX)
			return (-1);
	}
	return (result * sign);
}

/*
 * modified is_digit
*/
int	check_args(char **arv, int arc)
{
	int i;
	int j;

	i = 0;
	while (++i < arc)
	{
		j = 0;
		if ((arv[i][0] == '0') && (arv[i][1] == '\0')) // if none of them cant be zero
		// if ((arv[1][0] == '0') && (arv[1][1] == '\0'))// if just philo cant be zero
		{
			printf("you need at least one philo\n");
			return (-1);
		}
		if (arv[i][0] == '\0')
		{
			printf("Arguments can not be empty string\n");
			return (-1);
		}
		if (arv[i][0] == '+')
			j++;
		while (arv[i][j] != '\0')
		{
			if ((arv[i][j] >= 48) && (arv[i][j] <= 57))
				j++;
			else
			{
				printf("Only accept digits\n");
				return (-1);
			}
		}
		if (ft_atoll(arv[i]) == -1)
		{
			printf("use arguments less than INT_MAX\n");
			return (-1);
		}
	}
	return (0);
}

int	parse(int arc, char **arv)
{
	if (arc < 5 || arc > 6)
		return (printf ("invalid ammount of arguments\n"), -1);
	if(check_args(arv, arc) == -1)
		return (-1);
	return (0);
}
