#include "spoons.h"

int	main(int ac, char **av)
{
	t_ph		*ph;
	t_shared	shared;

	if (!(ac == 6 || ac == 5))
		return(write(2, "Error\n", 6), 0);
	if (validinput(av) == 0)
		return (write(2, "Error\n", 6), 0);
	init_fork_mtx(&shared, ft_atoi(av[1]));
	init(&ph, &shared, ac, av);
	if ((threading(&shared)) == 1)
		perror("Error");
	exit_program(&shared);
	return (0);
}
