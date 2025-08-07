#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ft_swap(char **s1, char **s2)
{
	char *tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int main(int argc, char **argv)
{
	if(argc < 2)
		return (0);
	int i;
	int swapped = 1;

	while(swapped)
	{
		swapped = 0;
		i = 1;
		while(i < argc - 1)
		{
			if(strcmp(argv[i], argv[i + 1]) > 0)
			{
				ft_swap(&argv[i], &argv[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
	for(i = 1; i < argc; i++)
		printf("%s\n", argv[i]);
}
