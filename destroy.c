/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:23:53 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 13:24:04 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

void	destroy_all(t_shared *shared)
{
	int	f;

	f = 0;
	while (f < shared->filos[0].nb_filos)
	{
		pthread_mutex_destroy(&shared->forks[f]);
		f++;
	}
	pthread_mutex_destroy(&shared->dead);
	pthread_mutex_destroy(&shared->meal);
	pthread_mutex_destroy(&shared->w);
}

void	exit_program(t_shared *shared)
{
	destroy_all(shared);
	free(shared->forks);
	free(shared->filos);
	exit(1);
}

void	one_philo(t_shared *shared, t_ph *ph)
{
    pthread_mutex_lock(ph->left);
    ft_print_status(ph, "has taken a fork");
    usleep(ph->t_die * 1000);
    ft_print_status(ph, "died");
    pthread_mutex_unlock(ph->left);
    exit_program(shared);
}
