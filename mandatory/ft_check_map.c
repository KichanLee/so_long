/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:45:04 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/13 18:07:12 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_square(t_map map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map.mapstr[i])
	{
		j = 0;
		while (map.mapstr[i][j])
			++j;
		if (map.mapstr[i][j-1] == '\n')
			--j;
		if (j != map.width)
			error(4);
		++i;
	}
	if (i != map.height)
		error(4);
}

void check_allowedcharacter(t_map map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.mapstr[i][j] != '1' && map.mapstr[i][j] != '0' && map.mapstr[i][j] != 'P' && map.mapstr[i][j] != 'C' && map.mapstr[i][j] != 'E')
				error(4);
			++j;
		}
		++i;
	}
}


void check_aroundonlyone(t_map map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map.height)
	{
		if (map.mapstr[i][0] != '1')
			error(4);
		++i;
	}
	while (j < map.width)
	{
		if(map.mapstr[0][j] != '1')
			error(4);
		++j;
	}
}

void	check_dfs(t_map map, int num)
{
	int x_arr = {1, -1, 0, 0};
	int y_arr = {0, 0, 1, -1};
	int check[100];
	int x_loc = map.player[0];
	int y_loc = map.player[1];
	while ()
	{
		while ()
		{
			
		}
	}
	check_dfs(map, num + 1);
}

void	ft_check_map(t_map map)
{
	check_square(map);
	check_aroundonlyone(map);
	check_allowedcharacter(map);
	check_dfs(map);
}