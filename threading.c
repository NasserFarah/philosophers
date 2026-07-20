/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:25:17 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 13:25:18 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

void	*filo_hi(void *p)
{
	t_ph	*ph;

	ph = (t_ph *)p;
	while (102)
	{
		if (philo_is_dead(ph))
			break ;
		eat(ph);
		if (philo_is_dead(ph))
			break ;
		ft_print_status(ph, "is sleeping");
		usleep(ph->t_sleep * 1000);
		ft_print_status(ph, "is thinking");
		usleep(326); //
	}
	return (p);
}

void	*main_hi(void *p)
{
	t_ph	*f;

	f = (t_ph *)p;
	while (102)
	{
		if ((anyfilo_died(f)) == 1 || (everyfilo_ate(f)) == 1)
			break ;
		usleep(326);
	}
	return (p);
}

int	threading(t_shared *shared)
{
	pthread_t	detector;
	int			f;
	int			created;

	if ((pthread_create(&detector, NULL, &main_hi, shared->filos)) != 0)
		return (1);
	f = 0;
	created = 0;
	while (f < shared->filos[0].nb_filos)
	{
		if ((pthread_create(&shared->filos[f].thid, NULL, &filo_hi,
					&shared->filos[f])) != 0)
		{
			shared->alive = 1;
			while (created-- > 0)
				pthread_join(shared->filos[created].thid, NULL);
			pthread_join(detector, NULL);
			return (1);
		}
		created++;
		f++;
	}
	if ((pthread_join(detector, NULL)) != 0)
		return (1);
	f = 0;
	while (f < shared->filos[0].nb_filos)
	{
		if ((pthread_join(shared->filos[f].thid, NULL)) != 0)
			return (1);
		f++;
	}
	return (0);
}
