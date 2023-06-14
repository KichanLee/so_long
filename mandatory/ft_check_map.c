/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:45:04 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/14 18:57:36 by kichlee          ###   ########.fr       */
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
void	one_dfs(int x, int y, t_check *ch, t_map map)
{
	int	i;
	int nx;
	int ny;

	i = 0;
	ch->check_arr_one[x][y] = '1';
	while (i < 4)
	{
		nx = x + ch->dx[i];	
		ny = y + ch->dy[i];
		if(nx >= 0 && nx < map.width && ny >= 0 && ny < map.height && ch->check_arr_one[nx][ny] != '1')
		{
			//if (ch->check_arr_one[nx][ny] == 'E' || ch->check_arr_one[nx][ny] == '0' || ch->check_arr_one[nx][ny] == 'C' || ch->check_arr_one[nx][ny] == 'P')
			//{
				if(ch->check_arr_one[nx][ny] == 'E')
					ch->exitcount--;
			//}
			one_dfs(nx, ny, ch, map);
		}
		++i;
	}
}
void	two_dfs(int x, int y, t_check *ch, t_map map)
{
	int	i;
	int nx;
	int ny;

	i = 0;
	ch->check_arr_two[x][y] = '1';
	while (i < 4)
	{
		nx = x + ch->dx[i];	
		ny = y + ch->dy[i];
		if(nx >= 0 && nx < map.width && ny >= 0 && ny < map.height && ch->check_arr_two[nx][ny] != '1')
		{
			if(ch->check_arr_two[nx][ny] == 'C')
				ch->feedcount -= 1;
			two_dfs(nx, ny, ch, map);
		}
		++i;
	}
}

void	init_for_dfs(t_map map)
{
	t_check t;
	int		i;
	int		j;


	t.dx[0] = 1;
	t.dx[1] = -1;
	t.dx[2] = 0;
	t.dx[3] = 0;
	t.dy[0] = 0;
	t.dy[1] = 0;
	t.dy[2] = 1;
	t.dy[3] = -1;
	t.exitcount = 1;
	t.feedcount = map.feed;
	i = 0;

	t.check_arr_one = (char **)malloc(sizeof(char *) * map.height);
	t.check_arr_two = (char **)malloc(sizeof(char *) * map.height);

	if(!t.check_arr_one || !t.check_arr_two)
		error(4);
	while (i < map.height)
	{
		t.check_arr_one[i] = ft_strdup(map.mapstr[i]);
		if(!t.check_arr_one[i])
			return;
		t.check_arr_two[i] = ft_strdup(map.mapstr[i]);
		if(!t.check_arr_two[i])
			return;
		++i;
	}	
	one_dfs(map.player[0], map.player[1], &t, map);
	two_dfs(map.player[0], map.player[1], &t, map);
	printf("exit count : %d feed count : %d\n", t.exitcount, t.feedcount);
	if(t.exitcount != 0 || t.feedcount != 0)
		error(4);

}

void	ft_check_map(t_map map)
{
	check_square(map);
	check_aroundonlyone(map);
	check_allowedcharacter(map);
	init_for_dfs(map);
}