/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:36:15 by nel-ouad          #+#    #+#             */
/*   Updated: 2025/07/19 15:37:45 by nel-ouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

void	row_printer(int x, char f, char m, char l)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(f);
		else if (i == x - 1)
			ft_putchar(l);
		else
			ft_putchar(m);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (y > 0 && x > 0)
	{
		while (i < y)
		{
			if (i == 0)
				row_printer(x, '/', '*', '\\');
			else if (i == y - 1)
				row_printer(x, '\\', '*', '/');
			else
				row_printer(x, '*', ' ', '*');
			i++;
		}
	}
	else
		ft_putstr("nn hh\n");
}
