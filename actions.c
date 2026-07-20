/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:23:10 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 13:23:33 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

static void	take_forks(t_ph *ph)
{
	if (ph->phid % 2 == 0)
	{
		pthread_mutex_lock(ph->left);
		ft_print_status(ph, "has taken a fork");
		pthread_mutex_lock(ph->right);
		ft_print_status(ph, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(ph->right);
		ft_print_status(ph, "has taken a fork");
		pthread_mutex_lock(ph->left);
		ft_print_status(ph, "has taken a fork");
	}
}

static void	put_forks(t_ph *ph)
{
	pthread_mutex_unlock(ph->right);
	pthread_mutex_unlock(ph->left);
}

void	eat(t_ph *ph)
{
	take_forks(ph);
	if (ph->nb_filos == 1)
	{
		while (!philo_is_dead(ph))
			usleep(500);
		pthread_mutex_unlock(ph->left);
		return ;
	}
	pthread_mutex_lock(ph->meal);
	ph->last_meal = gettime();
	ph->eating_stts = 1;
	pthread_mutex_unlock(ph->meal);
	ft_print_status(ph, "is eating");
	usleep(ph->t_eat * 1000);
	pthread_mutex_lock(ph->meal);
	ph->eating_stts = 0;
	ph->mealsconsumed++;
	pthread_mutex_unlock(ph->meal);
	put_forks(ph);
}
