#include "spoons.h"

int     validinput(char **av)
{
        int     i;
        int     j;

        i = 1;
        j = 0;
        while(av[i] !=NULL)
        {
                j = 0;
                while(av[i][j])
                {
                        if(!(av[i][j] > 47 && av[i][j] < 58))
                                return (0);
                        j++;
                }
                if ((ft_atoi(av[i]) < 0))
                        return (0);
                if (i != 5 && (ft_atoi(av[i])) == 0)
                        return (0);
                i++;
        }
        return (1);
}
