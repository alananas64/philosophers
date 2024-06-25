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
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (-1);
	}
	return (result * sign);
}

/*
 * modified is_digit
*/
int	ft_isdigit(char **arv, int arc)
{
	int i;
	int j;

	i = 0;
	while (++i < arc)
	{
		j = 0;
		if (arv[i][0] == '\0')
			return (-1);
		if (arv[i][0] == '+')
			j++;
		while (arv[i][j] != '\0')
		{
			if ((arv[i][j] >= 48) && (arv[i][j] <= 57))
				j++;
			else
				return (-1);
		}
	}
	return (0);
}
