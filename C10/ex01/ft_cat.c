/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:53:42 by nel-ouad          #+#    #+#             */
/*   Updated: 2025/08/04 17:53:46 by nel-ouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h> 
#include <stdio.h> 

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	print_error(char *prog_name, char *file_name)
{
	write(2, basename(prog_name), ft_strlen(basename(prog_name)));
	write(2, ": ", 2);
	write(2, file_name, strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	ft_std_in_out(int f)
{
	char	buffer[29000];
	ssize_t	bytes_read;

	bytes_read = read(f, buffer, 29000);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(f, buffer, 29000);
	}
}

void	ft_display_file(int ac, char **av)
{
	int		file;
	int		i;

	i = 1;
	while (i < ac)
	{
		file = open(av[i], O_RDONLY);
		if (file == -1)
			print_error(av[0], av[i]);
		else
			ft_std_in_out(file);
		close(file);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_std_in_out(0);
	else
		ft_display_file(argc, argv);
	return (0);
}
