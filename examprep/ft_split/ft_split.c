#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int len = 0;
	while(str[len])
		len++;
	return (len);
}

int is_sep(char c, char *sep)
{
	while(*sep)
	{
		if(*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

int ft_countwords(char *str, char *sep)
{
	int wc;
	int word;

	wc = 0;
	word = 1;
	while(*str)
	{
		if(!is_sep(*str, sep))
		{
			if(word)
				wc++;
			word = 0;
		}
		else
			word = 1;
		str++;
	}
	return (wc);
}

char *ft_strdup(char **str, char *sep)
{
	char *res;
	int	i;
	int start;
	int end;

	start = 0;
	while(is_sep((*str)[start], sep))
		start++;
	end = start;
	while(!is_sep((*str)[end], sep))
		end++;
	res = malloc(sizeof(char) * (end - start + 1));
	if(!res)
		return (NULL);
	i = 0;
	while(start < end)
	{
		res[i] = (*str)[start];
		i++;
		start++;
	}
	res[i] = '\0';
	*str += end;
	return (res);
}

char **ft_split(char *str, char *sep)
{
	char **arr;
	int wc;
	int i;

	wc = ft_countwords(str, sep);
	arr = malloc(sizeof(char *) * (wc + 1));
	if(!arr)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		arr[i] = ft_strdup(&str, sep);
		i++;
	}
	return (arr);
}

int main(void)
{
	char **arr = ft_split("split this into 5 parts", " ");
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	printf("%s\n", arr[3]);
	printf("%s\n", arr[4]);
}
