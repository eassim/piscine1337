/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:03:58 by eassim            #+#    #+#             */
/*   Updated: 2025/07/17 18:06:42 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_pair(int a, int b, int *first)
{
	char	digits[4];

	if (!*first)
		write(1, ", ", 2);
	else
		*first = 0;
	digits[0] = (a / 10) + '0';
	digits[1] = (a % 10) + '0';
	digits[2] = (b / 10) + '0';
	digits[3] = (b % 10) + '0';
	write(1, &digits[0], 1);
	write(1, &digits[1], 1);
	write(1, " ", 1);
	write(1, &digits[2], 1);
	write(1, &digits[3], 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	first;

	first = 1;
	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_pair(a, b, &first);
			b++;
		}
		a++;
	}
}
