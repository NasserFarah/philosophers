#include "spoons.h"

void	*filo_hi(void *p)
{
	(void)p;
	return NULL;
}

void	*hi(void *p)
{
	t_ph	*f;

	f = (t_ph *)p;
	while (112)
	{
		if ((anyfilo_died(f)) == 1 || (everyfilo_ate(f)) == 1)
			break;
	}
	(void)p;
	return (p);
}

int	threading(t_shared *shared)
{
	pthread_t	detector;
	int		f;

	if ((pthread_create(&detector, NULL, &hi, shared->filos)) != 0)
		return (1);
	f = 0;
	while (f < shared->filos[0].nb_filos)
	{
		if ((pthread_create(&shared->filos[f].thid, NULL, &filo_hi,
					       	&shared->filos[f])) != 0)
			return (1);
		f++;
	}
	f = 0;
	if ((pthread_join(detector, NULL)) != 0)
		return (1);
	while (f < shared->filos[0].nb_filos)
	{
		if ((pthread_join(shared->filos[f].thid, NULL)) != 0)
			return (1);
		f++;
	}
	return (0);
}
