#include "ft.h"

int	ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char *ft_strcpy(char *des, char *src)
{
	int  i = 0;
	while (src[i])
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}

char *ft_strdup(char *str)
{
	char *res;
	int i;
	int len = ft_strlen(str);

	res = malloc(sizeof(char) * (len + 1));
	i = -1;
	while(str[++i])
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}
char *ft_strcat(char *des, char *src)
{
	int i = 0;
	int len = ft_strlen(des);

	while(src[i])
	{
		des[len + i] = src[i];
		i++;
	}
	des[len + i] = '\0';
	return (des);
}
char *ft_strjoin(char **strs, char *sep)
{
	char *str;
	int n_words = 0;
	int i = 0;
	int size = 0;
	char *empty = "\0";

	while (strs[n_words])
		n_words++;
	while (i < n_words)
	{
		size += ft_strlen(strs[i]);
		i++;
	}
	size += ft_strlen(sep) * (n_words - 1);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (empty);
	i = 0;
	str[0] = '\0';
	while (i < n_words)
	{
		ft_strcat(str, strs[i]);
		if (i != n_words - 1)
			ft_strcat(str, sep);
		i++;
	}
	str[size] = '\0';
	return (str);
}
