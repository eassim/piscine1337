/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <eassim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:16:03 by eassim            #+#    #+#             */
/*   Updated: 2025/08/03 01:15:27 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	nbr;

	nbr = 0;
	i = 0;
	neg = 1;
	while (str[i] && (str[i] == ' ' || (str[i] > 8 && str[i] < 13)))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'
			|| (str[i] >= '0' && str[i] <= '9')))
	{
		if (str[i] == '-')
			neg *= -1;
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * neg);
}

void	ft_putnbr(int nb)
{
	int		power;
	char	c;

	power = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb *= -1;
	}
	while (nb / power > 9)
		power *= 10;
	while (power > 0)
	{
		c = nb / power % 10 + '0';
		write(1, &c, 1);
		power /= 10;
	}
}

void	ft_calc(char *s1, char *s2, char *op, int (*f)(int, int))
{
	int	a;
	int	b;
	int	nbr;

	a = ft_atoi(s1);
	b = ft_atoi(s2);
	if (b == 0 && !ft_strcmp(op, "/"))
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	if (b == 0 && !ft_strcmp(op, "%"))
	{
		ft_putstr("Stop: modulo by zero");
		return ;
	}
	nbr = f(a, b);
	ft_putnbr(nbr);
}
