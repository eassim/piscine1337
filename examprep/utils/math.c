#include "ft.h"

int ft_atoi(char *str)
{
	int neg = 1;
	int n = 0;

	while(*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			neg = -1;
		str++;
	}
	while(*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * neg);
}

int ft_isbase(char *base)
{
	int i = 0;
	int j;
	if(ft_strlen(base) < 2)
		return (0);
	while(base[i])
	{
		if(base[i] == '-' || base[i] == '+' || base[i] == ' ' || (base[i] > 8 && base[i] < 14))
			return (0);
		j = i + 1;
		while(base[j])
		{
			if(base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_inbase(char c, char *base)
{
	int i = 0;

	while(base[i])
	{
		if(c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoibase(char *str, char *base)
{
	int neg = 1;
	int n = 0;
	int b = ft_strlen(base);
	int i;

	if(!ft_isbase(base))
		return (0);
	while(*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			neg = -1;
		str++;
	}
	i = ft_inbase(*str, base);
	while(i != -1)
	{
		n = n * b + i;
		str++;
		i = ft_inbase(*str, base);
	}
	return (n * neg);
}

void ft_putnbr(int nbr)
{
	char c;
	long nb = nbr;
	if(nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if(nb <= 9)
	{
		c = nb + '0';
		write(1, &c, 1);
		return;
	}
	ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}

void ft_putnbrbase(int nbr, char *base)
{
	int b = ft_strlen(base);
	long nb = nbr;
	char c;

	if(!ft_isbase(base))
		return;
	if(nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if(nb < b)
	{
		c = base[nb];
		write(1, &c, 1);
		return;
	}
	ft_putnbrbase(nb / b, base);
	ft_putnbrbase(nb % b, base);
}

char *ft_retnbrbase(int nbr, char *base)
{
	int power = 1;
	int b = ft_strlen(base);
	long nb = nbr;
	int neg = 0;
	int len = 1;
	int i;

	if(!ft_isbase(base))
		return (NULL);
	if(nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	while(nb / power >= b)
	{
		power *= b;
		len++;
	}
	char *ret = malloc(len + neg + 1);
	i = 0;
	if(neg)
	{
		ret[0] = '-';
		i = 1;
	}

	while(i < len)
	{
		ret[i] = base[nb / power];
		nb %= power;
		power /= b;
		i++;
	}
	return (ret);
}

char *ft_convert_base(char *str, char *base_from, char *base_to)
{
	if(!(ft_isbase(base_from) && ft_isbase(base_to)))
		return (NULL);
	long n_dec = ft_atoibase(str, base_from);
	return (ft_retnbrbase(n_dec, base_to));
}
