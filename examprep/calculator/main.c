#include "ft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int (*operations[5])(int, int);
	int r;

	operations[0] = add;
	operations[1] = sub;
	operations[2] = mul;
	operations[3] = ft_div;
	operations[4] = mod;

	if(argc != 4)
		return (0);
	int a = atoi(argv[1]);
	int b = atoi(argv[3]);
	char *op = argv[2];
	r = 0;
	if (strcmp(op, "+") == 0)
		r = operations[0](a, b);
	if (strcmp(op, "-") == 0)
		r = operations[1](a, b);
	if (strcmp(op, "*") == 0)
		r = operations[2](a, b);
	if (strcmp(op, "/") == 0)
	{
		if (b == 0)
		{
				printf("Can't divide by 0");
				return (0);
		}
		r = operations[3](a, b);
	}
	if (strcmp(op, "%") == 0)
	{
		if (b == 0)
		{
				printf("Can't modulo by 0");
				return (0);
		}
		r = operations[4](a, b);
	}
	printf("%d", r);
}
