/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:56:12 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/09 01:04:41 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int ac, char **av)
{
	int		fd;
	t_map	map;
	char	*str;
	t_list	*first;
	int		i;

	fd	= open(av[1], O_RDONLY);

	first = get_map(fd);	
	ft_mapdownload(&map, &first);
	ft_find_all(&map);

	
	
	//map.mlx = mlx_init();
	//map.win = mlx_new_window(map.mlx,  map.width * 50, map.height * 50, "wonie");
	//mlx_loop(map.mlx);
	
}