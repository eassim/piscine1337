/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 04:15:47 by eassim            #+#    #+#             */
/*   Updated: 2025/07/21 06:56:22 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + ft_strlen(++str));
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(to_find);
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (*str)
	{
		i = 0;
		while (i < len && str[i] == to_find[i])
		{
			i++;
		}
		if (i == len)
			return (str);
		str++;
	}
	return (0);
}
