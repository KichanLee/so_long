/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:12:48 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/16 16:12:33 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player[0];
	y = map->player[1];
	if (map->mapstr[x][y -1] != '1' && map->mapstr[x][y -1] != 'E')
	{
		if (map->mapstr[x][y - 1] == 'C')
			map->feed -= 1;
		map->player[1] = y - 1;
		map->mapstr[map->player[0]][map->player[1]] = 'P';
		map->mapstr[x][y] = '0';
		map->walkcount++;
	}
	if (map->feed == 0 && map->mapstr[x][y - 1] == 'E')
		exit(0);
	place_images(map);
}

void	ft_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player[0];
	y = map->player[1];
	if (map->mapstr[x][y + 1] != '1' && map->mapstr[x][y + 1] != 'E')
	{
		if (map->mapstr[x][y + 1] == 'C')
			map->feed -= 1;
		map->player[1] = y + 1;
		map->mapstr[map->player[0]][map->player[1]] = 'P';
		map->mapstr[x][y] = '0';
		map->walkcount++;
	}
	if (map->feed == 0 && map->mapstr[x][y + 1] == 'E')
		exit(0);
	place_images(map);
}

void	ft_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player[0];
	y = map->player[1];
	if (map->mapstr[x - 1][y] != '1' && map->mapstr[x - 1][y] != 'E')
	{
		if (map->mapstr[x - 1][y] == 'C')
			map->feed -= 1;
		map->player[0] = x - 1;
		map->mapstr[map->player[0]][map->player[1]] = 'P';
		map->mapstr[x][y] = '0';
		map->walkcount++;
	}
	if (map->feed == 0 && map->mapstr[x - 1][y] == 'E')
		exit(0);
	place_images(map);
}

void	ft_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player[0];
	y = map->player[1];
	if (map->mapstr[x + 1][y] != '1' && map->mapstr[x + 1][y] != 'E')
	{
		if (map->mapstr[x + 1][y] == 'C')
			map->feed -= 1;
		map->player[0] = x + 1;
		map->mapstr[map->player[0]][map->player[1]] = 'P';
		map->mapstr[x][y] = '0';
		map->walkcount++;
	}
	if (map->feed == 0 && map->mapstr[x + 1][y] == 'E')
		exit(0);
	place_images(map);
}

int	key(int key, t_map *map)
{
	int	cnt;

	cnt = map->walkcount;
	if (key == KEY_W)
		ft_up(map);
	else if (key == KEY_A)
		ft_left(map);
	else if (key == KEY_D)
		ft_right(map);
	else if (key == KEY_S)
		ft_down(map);
	else if (key == KEY_ESC)
		exit(0);
	if (cnt != map->walkcount)
		showwalk(map);
	return (0);
}
