/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:23:44 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 13:23:46 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

int	philo_is_dead(t_ph *ph)
{
	int	stts;

	pthread_mutex_lock(ph->dead);
	stts = *ph->status;
	pthread_mutex_unlock(ph->dead);
	return (stts);
}

int	everyfilo_ate(t_ph *ph)
{
	int	f;
	int	complete_meals;

	f = 0;
	complete_meals = 0;
	if (ph[0].nb_meals < 0)
		return (0);
	while (f < ph[0].nb_filos)
	{
		pthread_mutex_lock(ph[f].meal);
		if (ph[f].mealsconsumed >= ph[f].nb_meals)
			complete_meals++;
		pthread_mutex_unlock(ph[f].meal);
		f++;
	}
	if (complete_meals == ph[0].nb_filos)
	{
		pthread_mutex_lock(ph[0].dead);
		*ph[0].status = 1;
		pthread_mutex_unlock(ph[0].dead);
		return (1);
	}
	return (0);
}

int	anyfilo_died(t_ph *ph)
{
	int	f;
	int	stts;

	f = 0;
	while (f < ph[0].nb_filos)
	{
		pthread_mutex_lock(ph[f].meal);
		if ((size_t)(gettime() - ph[f].last_meal) >= ph[f].t_die
			&& ph[f].eating_stts == 0)
			stts = 1;
		else
			stts = 0;
		pthread_mutex_unlock(ph[f].meal);
		if (stts)
		{
			pthread_mutex_lock(ph[0].w);
			pthread_mutex_lock(ph[f].dead);
			*ph[0].status = 1;
			printf("%zu %d died\n", gettime() - ph[f].t_init, ph[f].phid);
			pthread_mutex_unlock(ph[f].dead);
			pthread_mutex_unlock(ph[0].w);
			return (1);
		}
		f++;
	}
	return (0);
}
