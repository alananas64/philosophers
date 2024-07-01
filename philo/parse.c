#include "philo.h"

/**
 * modified atoll
 * @param str
 * @return (result * sign) if within range of int
 */
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
        if (str[i++] == 45)
            sign *= -1;
        i++;
    }
    while (str[i])
    {
        result = result * 10 + str[i] - '0';
        i++;
        if (result * sign <= 0 || result * sign > INT_MAX)
            return (-1);
    }
    return (result * sign);
}

/*
 * modified is_digit
*/
int	check_args(char **av, int ac)
{
    int i;
    int j;

    i = 0;
    while (++i < ac)
    {
        j = 0;
        if ((av[i][0] == '0') && (av[i][1] == '\0')) // if none of them cant be zero
            // if ((av[1][0] == '0') && (av[1][1] == '\0'))// if just philo cant be zero
        {
            return (printf("you need at least one philo\n"), -1);
        }
        if (av[i][0] == '\0')
            return (printf("Arguments can not be empty string\n"), -1);
        if (av[i][0] == '+')
            j++;
        while (av[i][j] != '\0')
        {
            if ((av[i][j] >= 48) && (av[i][j] <= 57))
                j++;
            else
                return (printf("%s: invalid argument {%s}\n", av[0], av[i]), -1);
        }
        if (ft_atoll(av[i]) == -1)
            return (printf("%s: invalid argument {%s}\n", av[0], av[i]), -1);
    }
    return (0);
}

int	parse(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf ("invalid ammount of arguments\n"), -1);
	if (check_args(av, ac) == -1)
		return (-1);
	return (0);
}
