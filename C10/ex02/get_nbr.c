#include <unistd.h>

char *get_bytes_nb_helper(int i, int diff, char *av)
{
	char *bytes_nb;
	bytes_nb = malloc((ft_strlen(av) - diff) + 1);
	while (i < ft_strlen(av))
	{
		bytes_nb[i - diff] = av[i];
		i++;
	}
	bytes_nb[i] = '\0';
	return (bytes_nb);
}

char *get_bytes_nb(int ac, char **av)
{
	char *bytes_nb;
	
	if (ft_strlen(av[1]) > 2)
		bytes_nb = get_bytes_nb_helper(2, 2, av[1]);
	else if (ac >= 3)
		bytes_nb = get_bytes_nb_helper(0, 0, av[2]);
	else
		return (NULL);
	return (bytes_nb);
}