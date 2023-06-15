/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:56:12 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/15 21:58:02 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks()
{
	system("leaks a.out");
}


int main(int ac, char **av)
{
	int fd;
	t_map map;
	t_list *first;

	atexit(leaks);
	fd = open(av[1], O_RDONLY);
	if(fd < 0)
		exit(1);
	first = get_map(fd);
	ft_check_arg(ac, av);
	ft_mapdownload(&map, &first);
	ft_find_all(&map);
	ft_check_map(map, &map);
	free(first);
	printf("==================\n");
	system("leaks a.out");
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width * 50, map.height * 50, "kichan");
	place_images(&map);
	mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key, &map);
	//mlx_key_hook(map.win, &key, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_e, &map);
	mlx_loop(map.mlx);

}