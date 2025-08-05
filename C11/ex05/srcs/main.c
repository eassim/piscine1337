/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <eassim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:59:39 by eassim            #+#    #+#             */
/*   Updated: 2025/08/03 01:14:50 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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

int	main(int argc, char **argv)
{
	int	(*operations[5])(int, int);

	if (argc != 4)
		return (0);
	operations[0] = ft_add;
	operations[1] = ft_sub;
	operations[2] = ft_mul;
	operations[3] = ft_div;
	operations[4] = ft_mod;
	if (!ft_strcmp(argv[2], "+"))
		ft_calc(argv[1], argv[3], argv[2], operations[0]);
	else if (!ft_strcmp(argv[2], "-"))
		ft_calc(argv[1], argv[3], argv[2], operations[1]);
	else if (!ft_strcmp(argv[2], "*"))
		ft_calc(argv[1], argv[3], argv[2], operations[2]);
	else if (!ft_strcmp(argv[2], "/"))
		ft_calc(argv[1], argv[3], argv[2], operations[3]);
	else if (!ft_strcmp(argv[2], "%"))
		ft_calc(argv[1], argv[3], argv[2], operations[4]);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}	
