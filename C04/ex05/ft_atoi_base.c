/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:40:02 by eassim            #+#    #+#             */
/*   Updated: 2025/07/27 09:02:07 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
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

	if (!is_valid(base))
		return (0);
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
