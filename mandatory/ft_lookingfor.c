/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lookingfor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:17:36 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/15 16:18:33 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_all(t_map *map)
{
	ft_find_player(map);
	ft_find_feed(map);
	ft_find_exit(map);
}

void	ft_find_feed(t_map *map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->mapstr[i][j] == 'C')
				++flag;
			++j;
		}
		++i;
	}
	map->feed = flag;
	if (flag == 0)
		error(3);
}

void	ft_find_player(t_map *map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->mapstr[i][j] == 'P')
			{
				map->player[0] = i;
				map->player[1] = j;
				++flag;
			}
			++j;
		}
		++i;
	}
	if (flag != 1)
		error(1);
}

void	ft_find_exit(t_map *map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->mapstr[i][j] == 'E')
			{
				map->finish[0] = j;
				map->finish[1] = i;
				++flag;
			}
			++j;
		}
		++i;
	}
	if (flag != 1)
		error(2);
}
