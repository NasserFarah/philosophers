/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:24:55 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 13:25:06 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

void	ft_print_status(t_ph *ph, char *msg)
{
	pthread_mutex_lock(ph->w);
	pthread_mutex_lock(ph->dead);
	if (*ph->status == 0)
		printf("%zu %d %s\n", gettime() - ph->t_init, ph->phid, msg);
	pthread_mutex_unlock(ph->dead);
	pthread_mutex_unlock(ph->w);
}