/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassim <eassim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:42:34 by eassim            #+#    #+#             */
/*   Updated: 2025/08/03 16:50:03 by eassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	decr;
	int	incr;

	i = 0;
	decr = 1;
	incr = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			decr = 0;
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			incr = 0;
		i++;
	}
	if (decr || incr)
		return (1);
	return (0);
}
