/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <eassim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:33:26 by eassim            #+#    #+#             */
/*   Updated: 2025/07/27 09:38:36 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_is_valid(char *base);
int		ft_in_base(char c, char *base);
int		ft_get_neg(char **str, char *base);
int		ft_atoi_base(char *str, char *base);

int	allocate(int nbr, char **res, int b)
{
	int	tmp;
	int	len;
	int	power;
	int	neg;

	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		tmp = -nbr;
	}
	else
		tmp = nbr;
	len = 0;
	power = 1;
	while (tmp / power >= b)
	{
		power *= b;
		len++;
	}
	*res = (char *)malloc(len + 1 + neg);
	if (nbr < 0)
		*res[0] = '-';
	return (power);
}

char	*ft_nbr_base(int nbr, char *base)
{
	int		power;
	int		b;
	char	*res;
	int		i;

	b = 0;
	while (base[b])
		b++;
	power = allocate(nbr, &res, b);
	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (power > 0)
	{
		res[i] = base[(nbr / power) % b];
		power /= b;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_decimal;
	char	*res;

	if (!ft_is_valid(base_from) || !ft_is_valid(base_to))
		return (NULL);
	nbr_decimal = ft_atoi_base(nbr, base_from);
	res = ft_nbr_base(nbr_decimal, base_to);
	return (res);
}
