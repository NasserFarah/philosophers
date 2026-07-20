/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:24:33 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 13:24:35 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

void	one_p(t_ph **ph, t_shared *shared, char **av, int f)
{
	(*ph)[f].phid = f + 1;
	(*ph)[f].eating_stts = 0;
	(*ph)[f].mealsconsumed = 0;
	(*ph)[f].nb_filos = ft_atoi(av[1]);
	(*ph)[f].t_die = ft_atoi(av[2]);
	(*ph)[f].t_eat = ft_atoi(av[3]);
	(*ph)[f].t_sleep = ft_atoi(av[4]);
	(*ph)[f].t_init = get_time_real(shared);
	(*ph)[f].last_meal = (*ph)[f].t_init;
	(*ph)[f].dead = &shared->dead;
	(*ph)[f].left = &shared->forks[f];
	if (f == 0)
		(*ph)[f].right = &shared->forks[(*ph)[f].nb_filos - 1];
	else
		(*ph)[f].right = &shared->forks[f - 1];
	(*ph)[f].w = &shared->w;
	(*ph)[f].dead = &shared->dead;
	(*ph)[f].meal = &shared->meal;
	(*ph)[f].status = &shared->alive;
}

// parses and inits the t_ph struct and t_shared
void	init(t_ph **ph, t_shared *shared, int ac, char **av)
{
	int	f;
	int	n;

	f = 0;
	n = ft_atoi(av[1]);
	*ph = malloc((n) * sizeof(t_ph));
	if (!*ph)
		exit(EXIT_FAILURE);
	while (f < n)
	{
		if (ac == 6)
			(*ph)[f].nb_meals = ft_atoi(av[5]);
		else
			(*ph)[f].nb_meals = -3;
		one_p(ph, shared, av, f);
		f++;
	}
	shared->alive = 0;
	shared->filos = *ph;
	pthread_mutex_init(&shared->w, NULL);
	pthread_mutex_init(&shared->meal, NULL);
	pthread_mutex_init(&shared->dead, NULL);
}

// initializes the forks mutex array
int	init_fork_mtx(t_shared *shared, int nb_filos)
{
	int	f;

	shared->forks = malloc(sizeof(pthread_mutex_t) * nb_filos);
	if (!(shared->forks))
		return (free((shared->forks)), 0);
	f = 0;
	while (f < nb_filos)
	{
		pthread_mutex_init(&(shared->forks)[f], NULL);
		f++;
	}
	return (1);
}
