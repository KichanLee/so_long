/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_walk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:25:46 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/16 16:37:02 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long	ft_len(int n)
{
	long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		++i;
	}
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;	
	long	n_size;
	long	l_n;

	l_n = (long) n;
	n_size = ft_len(n);
	str = malloc(n_size + 1);
	if (!str)
		return (0);
	if (l_n == 0)
		str[0] = '0';
	if (l_n < 0)
	{
		str[0] = '-';
		l_n *= -1;
	}
	str[n_size] = '\0';
	while (l_n > 0)
	{
		str[--n_size] = l_n % 10 + '0';
		l_n /= 10;
	}
	return (str);
}

void	showwalk(t_map *map)
{
	char	*str;
	int		i;
	int		len;

	str = NULL;
	i = 0;
	str = ft_itoa(map->walkcount);
	len = strlen(str);
	while (i < len)
	{
		write(1, &str[i], 1);
		++i;
	}
	write(1, "\n", 1);
	free(str);
}
