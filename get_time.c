#include "spoons.h"

ssize_t	gettime(void)
{
	ssize_t		time;
	struct timeval	t;

	time = gettimeofday(&t, NULL);
	if (time == -1)
		return (-1);
	time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (time);
}
