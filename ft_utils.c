/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:24:14 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 13:24:16 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > 2147483647L)
			return (2147483647);
		if (result * sign < -2147483648L)
			return (-2147483648);
		str++;
	}
	return ((int)(result * sign));
}

int	ft_strlen(char *str)
{
	int	l;

	if (str == NULL)
		return (0);
	l = 0;
	while (str[l])
		l++;
	return (l);
}
