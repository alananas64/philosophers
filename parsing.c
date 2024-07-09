/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:32:15 by nosman            #+#    #+#             */
/*   Updated: 2024/07/08 14:01:50 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
			printf("Args should be bigger than zero\n");
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
// int	is_numeric(int count)
// {
// 	if (count >= 48 && count <= 57)
// 		return (1);
// 	else
// 		return (0);
// }

// int	is_str_numeric(char *str)
// {
// 	int	i;

// 	i = -1;
// 	if (str[0] == '\0')
// 		return (0);
// 	if (str[0] == '-' || str[0] == '+')
// 		i++;
// 	while (str[++i])
// 	{
// 		if (is_numeric(str[i]) == 0)
// 			return (0);
// 	}
// 	return (1);
// }

// int	args_all_num(char **av)
// {
// 	int	i;

// 	i = 0;
// 	while (av[++i])
// 	{
// 		if (!is_str_numeric(av[i]))
// 		{
// 			ft_putstr_fd("Invalid arguments\n", 2);
// 			return (1);
// 		}
// 		if (ft_atoi_l(av[i]) > INT_MAX)
// 		{
// 			ft_putstr_fd("Inputs should be below INT_MAX\n", 2);
// 			return (1);
// 		}
// 		if (ft_atoi_l(av[i]) <= 0)
// 		{
// 			ft_putstr_fd("Inputs should be greater than 0\n", 2);
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

// int	arg_num(int ac)
// {
// 	if (ac == 5 || ac == 6)
// 		return (0);
// 	else
// 	{
// 		ft_putstr_fd("Invalid number of arguments\n", 2);
// 		return (1);
// 	}
// }
