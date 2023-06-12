/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_download.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:06:03 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/12 20:34:40 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_mapdownload(t_map *map, t_list **list)
{
    t_list  *head;
    int     i;

    i = 0;
    head = *list;
    map->width = ft_strlen_d(head->content) -1;
    map->height = ft_lstsize(head);
    
    map->mapstr = (char **)ft_calloc(map->height, sizeof(char *));
    
    while (i < map->height)
    {
        map->mapstr[i] = ft_strdup(head->content);
        printf("%s\n", map->mapstr[i]);
        head = head->next;
        ++i;
    }
}

