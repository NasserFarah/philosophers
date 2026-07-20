/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnasser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:24:24 by fnasser           #+#    #+#             */
/*   Updated: 2026/07/14 13:24:26 by fnasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spoons.h"

ssize_t	gettime(void)
{
	ssize_t			time;
	struct timeval	t;

	time = gettimeofday(&t, NULL);
	if (time == -1)
		return (-1);
	time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (time);
}

ssize_t	get_time_real(t_shared *shared)
{
	struct timeval	t;

	if ((gettimeofday(&t, NULL)) == 0)
		return (t.tv_sec * 1000 + t.tv_usec / 1000);
	return (exit_program(shared), 0);
}
