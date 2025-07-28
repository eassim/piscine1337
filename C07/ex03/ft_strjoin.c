/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:29:21 by eassim            #+#    #+#             */
/*   Updated: 2025/07/28 21:03:30 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + ft_strlen(++str));
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	len = ft_strlen(dest);
	i = -1;
	while (src[++i])
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}

int	calc_length(int size, char **strs, char *sep)
{
	int	i;
	int	total_length;

	i = 0;
	total_length = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		if (i < size - 1)
			total_length += ft_strlen(sep);
		i++;
	}
	return (total_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		total_length;
	char	*empty;

	if (size == 0)
	{
		empty = malloc(1);
		empty[0] = '\0';
		return (empty);
	}
	total_length = calc_length(size, strs, sep);
	res = (char *)malloc((sizeof(char)) * total_length + 1);
	i = 0;
	res[i] = '\0';
	while (i < size)
	{
		if (i != 0)
			ft_strcat(res, sep);
		res = ft_strcat(res, strs[i]);
		i++;
	}
	res[total_length] = '\0';
	return (res);
}
