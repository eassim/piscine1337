int fdt_atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	// Skip whitespace
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	// Handle sign
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	// Convert digits
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return sign * result;
}
