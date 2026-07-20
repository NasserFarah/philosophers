/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:25:45 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 14:53:58 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

// checks for numbers
// checks that the nbs are valid(not 0 except nb_times_must_eat)

int	validinput(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] > 47 && av[i][j] < 58))
				return (0);
			j++;
		}
		if ((ft_atoi(av[i]) < 0))
			return (0);
		if (i != 5 && (ft_atoi(av[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}
