/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:01:18 by nel-ouad          #+#    #+#             */
/*   Updated: 2025/07/30 13:01:19 by nel-ouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchars(char *buff, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &buff[i], 1);
		i++;
	}
}

void	ft_display_file(char *filename)
{
	int		file;
	char	buffer[1024];
	ssize_t	reader;

	file = open(filename, O_RDONLY);
	if (file == -1)
		ft_putstr("Cannot read file.\n");
	else
	{
		while (1)
		{
			reader = read(file, buffer, 1024);
			if (reader <= 0)
				break ;
			ft_putchars(buffer, reader);
		}
	}
	close(file);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		ft_display_file(argv[1]);
	return (0);
}
