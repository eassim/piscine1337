/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:35:44 by nel-ouad          #+#    #+#             */
/*   Updated: 2025/07/23 08:35:49 by nel-ouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	print_comb(int *buff, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		put_char(buff[i] + '0');
		i++;
	}
	if (buff[0] < 10 - n)
	{
		put_char(',');
		put_char(' ');
	}
}

void	comb_generator(int *buff, int index, int n)
{
	int	i;

	if (index == n)
	{
		print_comb(buff, n);
		return ;
	}
	if (index == 0)
		i = 0;
	else
		i = buff[index - 1] + 1;
	while (i <= 10 - n + index)
	{
		buff[index] = i;
		comb_generator(buff, index + 1, n);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	buff[10];

	if (n <= 0 || n >= 10)
		return ;
	comb_generator(buff, 0, n);
}
