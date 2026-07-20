/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:24:40 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 13:24:42 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

int	main(int ac, char **av)
{
	t_ph		*ph;
	t_shared	shared;

	if (!(ac == 6 || ac == 5))
		return (write(2, "Error\n", 6), 1);
	if (validinput(av) == 0)
		return (write(2, "Error\n", 6), 1);
	if ((init_fork_mtx(&shared, ft_atoi(av[1]))) == 0 )
		return (write(2, "Error\n", 6), 1);
	init(&ph, &shared, ac, av);
	if (ph->nb_filos == 1)
		return (one_philo(&shared, ph), 0);
	if ((threading(&shared)) == 1)
		perror("Error");
	exit_program(&shared);
	return (0);
}
