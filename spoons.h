#  ifndef SPOONS_H
# define SPOONS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct	s_ph
{
	int		*status;
	int		phid;
	int		eating_stts;
	int		mealsconsumed;
	int		nb_filos;
	int		nb_meals;
	pthread_t	thid;
	size_t		last_meal;
	size_t		t_eat;
	size_t		t_sleep;
	size_t		t_die;
	size_t		t_init;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	pthread_mutex_t	*w;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*meal;
}		t_ph;

typedef struct	s_shared
{
	t_ph		*filos;
	int		alive;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead;
	pthread_mutex_t	meal;
	pthread_mutex_t	w;
}		t_shared;

int     ft_atoi(const char *str);
void    exit_program(t_shared *shared);
ssize_t get_time_real(t_shared* shared);
void    init(t_ph **ph,t_shared *shared, int ac, char **av);
int     init_fork_mtx(t_shared *shared, int nb_filos);
int     threading(t_shared *shared);
ssize_t gettime(void);
int     everyfilo_ate(t_ph *ph);
int     anyfilo_died(t_ph *f);
int     validinput(char **av);

#endif
