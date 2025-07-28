/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:50:48 by eassim            #+#    #+#             */
/*   Updated: 2025/07/18 11:01:02 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printchar(char c)
{
	write(1, &c, 1);
}

void	printnumber(int n)
{
	int	a;
	int	b;
	
	if (n == 0)
	{
		write(1, '0', 1);
	}
	if (n < 0)
	{
		write(1, '-', 1);
		n = n * -1;
		printnumber(n);
	}
	if (n < '9')
	{
		write
	a = (n / 10) + '0';
	b = (n % 10) + '0';

int	main(int n)
{
	return (0);
}
