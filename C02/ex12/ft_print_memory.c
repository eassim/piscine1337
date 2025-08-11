/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:46:00 by nel-ouad          #+#    #+#             */
/*   Updated: 2025/07/24 10:46:03 by nel-ouad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c1, char c2, char *str)
{
	if (c1)
		write(1, &c1, 1);
	if (c2)
		write(1, &c2, 1);
	while (*str)
		write(1, str++, 1);
}

char	*to_hex(char *buff, unsigned long address)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		buff[15 - i] = hex[address % 16];
		address /= 16;
		i++;
	}
	buff[16] = '\0';
	return (buff);
}

void	hex_row_printer(char *str)
{
	int		i;
	char	*hex;
	int		incomplete;

	hex = "0123456789abcdef";
	incomplete = 0;
	i = 0;
	put_char(' ', '\0', "\0");
	while (i < 16 && *str)
	{
		put_char(hex[*str / 16], hex[*(str) % 16], "\0");
		if (i % 2 == 1)
			put_char(' ', '\0', "\0");
		str++;
		i++;
	}
	while (i < 16)
	{
		put_char(' ', ' ', "\0");
		if (i % 2 == 1)
			put_char(' ', '\0', "\0");
		i++;
	}	
}

char	*ultimate_printer(int i, char *buff, char *str)
{
	char	j;

	j = 0;
	if (i % 16 == 0)
	{
		put_char('\0', '\0', to_hex(buff, (unsigned long)str));
		write(1, ":", 1);
		hex_row_printer(str);
		j = 0;
		while (*str && j < 16)
		{
			if (*str >= 32 && *str <= 126)
				write(1, str, 1);
			else
				write(1, ".", 1);
			str++;
			j++;
		}
		write(1, "\n", 1);
	}
	return (str);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*str;
	unsigned int	i;
	char			buff[17];

	if (size <= 0)
		return (addr);
	str = (char *)addr;
	i = 0;
	while (*str && i < size)
	{
		str = ultimate_printer(i, buff, str);
		i++;
	}
	return (addr);
}
