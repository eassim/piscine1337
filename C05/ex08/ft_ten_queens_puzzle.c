/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:16:09 by eassim            #+#    #+#             */
/*   Updated: 2025/07/23 16:28:00 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid(char	*placement, int pos, char queen)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (placement[i] == queen || (pos - i) == (placement[i] - queen)
			|| (pos - i) == (queen - placement[i]))
			return (0);
		i++;
	}
	return (1);
}

void	solve(char *placement, int pos, int *count)
{
	char	queen;

	if (pos == 10)
	{
		ft_putstr(placement);
		write(1, "\n", 1);
		(*count)++;
		return ;
	}
	queen = '0';
	while (queen <= '9')
	{
		if (is_valid(placement, pos, queen))
		{
			placement[pos] = queen;
			solve(placement, pos + 1, count);
			placement[pos] = '\0';
		}
		queen++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	placement[11];
	int		count;
	int		i;

	i = -1;
	while (i < 10)
		placement[++i] = 0;
	count = 0;
	solve(placement, 0, &count);
	return (count);
}
