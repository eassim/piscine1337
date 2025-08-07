#include "ft.h"
#include <stdio.h>

int	main()
{
	char *base_from = "0123456789";
	char *base_to = "0123456789abcdef";
	char *ret = ft_convert_base("6969", base_from, base_to);
	printf("%s", ret);
}
