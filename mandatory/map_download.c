/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_download.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:06:03 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/15 21:08:13 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_mapdownload(t_map *map, t_list **list)
{
    t_list  *head;
    int     i;

    i = 0;
    head = *list;
    printf("list address : %p \n", *list);
    map->width = (int)ft_strlen_d(head->content) - 1;
    map->height = ft_lstsize(head); 
    map->mapstr = (char **)ft_calloc(map->height + 1, sizeof(char *));
    while (i < map->height)
    {
        map->mapstr[i] = ft_strdup(head->content);
        free(head->content);
        head = head->next;
        ++i;
    }
    ft_lstclear(list);
    printf("list second address : %p \n", *list);
}

