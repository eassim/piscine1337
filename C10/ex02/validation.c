int	ft_strlen(char *str);

int is_valid2(char nb)
{
    if (!((nb >= '0' && nb <= '9')
			|| nb == 'm' || nb == 'M'
			|| nb == 'k' || nb == 'K'
			|| nb == 'G' || nb == 'T'
		))
		return 0;
	return 1;
}

int is_valid(char *nb)
{
	int	i;

	i = 0;
	if (ft_strlen(nb) == 1)
	{
		if (!((nb[0] >= '0' && nb[0] <= '9')
			|| nb[0] == 'm' || nb[0] == 'M'
			|| nb[0] == 'k' || nb[0] == 'K'
			|| nb[0] == 'G' || nb[0] == 'T'
		))
		return 0;
	}
	else
	{
		while (i < ft_strlen(nb) - 1)
		{
			if (!(nb[i] >= '0' && nb[i] <= '9'))
				return 0;
            i++;
		}
		if (!is_valid2(nb[i]))
			return (0);
	}
	return (1);
}