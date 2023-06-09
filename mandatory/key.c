/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:12:48 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/09 17:28:04 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


void    ft_up(t_map *map)
{
    int x;
    int y;
    
    x =  map->player[0];
    y =  map->player[1];
    printf("%d  %d\n", x, y);
    if(map->mapstr[x][y -1] != '1' && map->mapstr[x][y -1] != 'E')
    {
        if(map->mapstr[x][y - 1] == 'C')
            map->feed - 1; 
        map->player[1] = y - 1; 
    }
    

}

int     key_press(int key ,t_map *map)
{
    if(key == KEY_W)
        ft_up(map);
        // &map 이 아니다.
    else if(key == KEY_A)
        ft_left(map);
    else if(key == KEY_D)
        ft_right(map);
    else if(key == KEY_S)
        ft_down(map);
    
    return (0);
}