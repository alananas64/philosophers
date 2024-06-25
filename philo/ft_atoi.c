/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:22:18 by nosman            #+#    #+#             */
/*   Updated: 2024/06/25 08:27:10 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	minlong(long n, int sign, char c)
{
	if ((((n == 922337203685477580) && (c > '8')) && (sign == -1))
		|| ((n > 922337203685477580) && (sign == -1)))
		return (1);
	else
		return (0);
}

static	int	maxlong(long n, int sign, char c)
{
	if (((n > 922337203685477580) && (sign == 1))
		|| ((n == 922337203685477580) && (sign == 1) && (c > '7')))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (maxlong(result, sign, str[i]) == 1)
			return (-1);
		else if (minlong(result, sign, str[i]) == 1)
			return (0);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
