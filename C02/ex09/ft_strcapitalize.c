/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:37:42 by eassim            #+#    #+#             */
/*   Updated: 2025/07/20 23:00:23 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
		{
			str[i] -= 'Z' - 'z';
		}
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	ft_strlowcase(str);
	while (str[++i])
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 'z' - 'Z';
		}
		if ((str[i] < 'A') || (str[i] > 'Z' && str[i] < 'a') || (str[i] > 'z'))
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
			{
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				{
					str[i + 1] -= 'z' - 'Z';
				}
			}
		}
	}
	return (str);
}
