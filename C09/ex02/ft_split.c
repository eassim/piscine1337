/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <eassim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:32:33 by eassim            #+#    #+#             */
/*   Updated: 2025/08/03 03:41:39 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	wc;
	int	word;

	wc = 0;
	word = 1;
	while (*str)
	{
		if (!is_sep(*str, charset))
		{
			if (word)
				wc++;
			word = 0;
		}
		else
			word = 1;
		str++;
	}
	return (wc);
}

char	*ft_strdup(char **str, char *charset)
{
	int		start;
	int		end;
	int		i;
	char	*dup;
	char	*res;

	dup = *str;
	start = 0;
	while (dup[start] && is_sep(dup[start], charset))
		start++;
	end = start;
	while (dup[end] && !is_sep(dup[end], charset))
		end++;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
	{
		res[i] = dup[start];
		i++;
		start++;
	}
	res[i] = '\0';
	*str += end;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	int		idx;
	int		wc;
	char	**res;

	if (!str || !charset)
		return (NULL);
	wc = word_count(str, charset);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	idx = 0;
	while (idx < wc)
	{
		res[idx] = ft_strdup(&str, charset);
		idx++;
	}
	res[idx] = 0;
	return (res);
}
