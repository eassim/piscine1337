/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <eassim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:46:11 by eassim            #+#    #+#             */
/*   Updated: 2025/07/28 16:58:28 by eassim           ###   ########.fr       */
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

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(charset))
		if (c == charset[i])
			return (1);
	return (0);
}

int	ft_wordcount(char *str, char *charset)
{
	int	count;
	int	i;
	int	word;

	i = 0;
	word = 1;
	count = 0;
	while (str[i])
	{
		if (!ft_is_sep(str[i], charset))
		{
			if (word)
				count++;
			word = 0;
		}
		else
			word = 1;
		i++;
	}
	return (count);
}

void	ft_strdup(char **res, char **str, char *charset, int idx)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	while ((*str)[start] && ft_is_sep((*str)[start], charset))
		start++;
	end = start;
	while ((*str)[end] && !ft_is_sep((*str)[end], charset))
		end++;
	res[idx] = (char *)malloc(end - start + 1);
	if (!res[idx])
		return ;
	i = 0;
	while (start < end)
	{
		res[idx][i] = (*str)[start];
		i++;
		start++;
	}
	res[idx][i] = '\0';
	*str += end;
}

char	**ft_split(char *str, char *charset)
{
	int		idx;
	int		wc;
	char	**res;

	wc = ft_wordcount(str, charset);
	if (wc == 0)
		return (NULL);
	res = (char **)malloc(8 * (wc + 1));
	idx = 0;
	while (idx < wc)
	{
		ft_strdup(res, &str, charset, idx);
		idx++;
	}
	res[wc] = 0;
	return (res);
}
