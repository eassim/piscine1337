#include <unistd.h>

int	main(int n, char **args)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		while(args[1][i])
		{
			write(1, &args[1][i++], 1);
		}
	}
}
