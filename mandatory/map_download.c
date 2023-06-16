/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_download.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:06:03 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/16 16:14:32 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapdownload(t_map *map, t_list **list)
{
	t_list	*head;
	int		i;

	i = 0;
	head = *list;
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
}
