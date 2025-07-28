/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <eassim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:40:08 by eassim            #+#    #+#             */
/*   Updated: 2025/07/27 10:42:17 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_valid(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] > 8 && base[i] < 13))
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

int	ft_in_base(char c, char *base)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(base);
	while (i < len)
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_neg(char **str, char *base)
{
	int	neg;

	neg = 1;
	while (**str && (**str == ' ' || (**str > 8 && **str < 13)))
		(*str)++;
	while (**str && (**str == '-' || **str == '+' || ft_in_base(**str, base)))
	{
		if (**str == '-')
			neg *= -1;
		if (ft_in_base(**str, base))
			break ;
		(*str)++;
	}
	return (neg);
}

int	ft_atoi_base(char *str, char *base)
{
	int	neg;
	int	nbr;
	int	b;
	int	idx;

	b = ft_strlen(base);
	nbr = 0;
	neg = ft_get_neg(&str, base);
	while (ft_in_base(*str, base))
	{
		idx = 0;
		while (*str != base[idx])
			idx++;
		nbr = nbr * b + idx;
		str++;
	}
	return (nbr * neg);
}
