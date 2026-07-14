#include "spoons.h"

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
		*ph->status = 1;
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
		if ((gettime() - ph[f].last_meal) >= ph[f].t_die && ph[f].eating_stts == 0)
			stts = 1;
		else
			stts = 0;
		pthread_mutex_unlock(ph[f].meal);
		if (stts)
		{
			pthread_mutex_lock(ph[0].dead);
			*ph->status = 1;
			pthread_mutex_unlock(ph[0].dead);
			return (1);
		}
		f++;
	}
	return (0);
}
