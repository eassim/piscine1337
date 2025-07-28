/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:40:02 by eassim            #+#    #+#             */
/*   Updated: 2025/07/27 09:07:08 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	n;
	long long	b;
	long long	power;

	b = ft_strlen(base);
	power = 1;
	n = nbr;
	if (!is_valid(base))
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n / power >= b)
		power *= b;
	while (power > 0)
	{
		write(1, &base[(n / power) % b], 1);
		power /= b;
	}
}
