/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lookingfor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:17:36 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/09 00:37:34 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_find_all(t_map *map)
{
    ft_find_player(map);
    ft_find_feed(map);
}

void    ft_find_player(t_map *map)
{
    int i;
    int j;
    int flag;

    i = 0;
    flag = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {   
            if(map->mapstr[i][j] == 'P')
            {
                map->player[0] = i; 
                map->player[1] = j;
                ++flag; 
            }
        }
    }
    if(flag != 1)


}