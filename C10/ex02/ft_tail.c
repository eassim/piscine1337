/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:06:55 by nel-ouad          #+#    #+#             */
/*   Updated: 2025/08/04 20:06:56 by nel-ouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h> 
#include <stdlib.h> 
#include <stdio.h> 

int is_valid(char *nb);
char *get_bytes_nb_helper(int i, int diff, char *av);
char *get_bytes_nb(int ac, char **av);
int	ft_strlen(char *str);
void ft_std_in();

void ft_display_file(char *bytes_nb, int ac, char **av)
{
	
}

void	ft_tail(int ac, char **av)
{
	char *bytes_nb;

	bytes_nb = get_bytes_nb(ac, av);
	if (!bytes_nb)
	{
		printf("tail: option requires an argument -- 'c'\n");
		return ;
	} else if (!is_valid(bytes_nb))
	{
		printf("tail: invalid number of bytes: '%s'\n", bytes_nb);
		return ;
	}
	else if ((is_valid(bytes_nb) && ac == 2)
	|| (
	(is_valid(bytes_nb) 
	&& ft_strlen(av[1]) == 2
	&& ac == 3)))
		ft_std_in();
	else
		ft_display_file(bytes_nb, ac, av);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_std_in();
	else
		ft_tail(argc, argv);
	return (0);
}

