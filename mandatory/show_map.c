/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:14:53 by kichan            #+#    #+#             */
/*   Updated: 2023/06/16 16:51:00 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_map *map, int x, int y, char *file)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(map->mlx, file, &img_width, &img_height);
	mlx_put_image_to_window(map->mlx, map->win, img, y * 50, x * 50);
	mlx_destroy_image(map->mlx, img);
}

void	make_base(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(map->mlx, map->win);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			put_img(map, y, x, "./pic/background_water.xpm");
			++x;
		}
		++y;
	}
}

void	place_images(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	make_base(map);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->mapstr[y][x] == 'P')
				put_img(map, y, x, "./pic/ggobuk.xpm");
			else if (map->mapstr[y][x] == 'C')
				put_img(map, y, x, "./pic/chu.xpm");
			else if (map->mapstr[y][x] == '1')
				put_img(map, y, x, "./pic/stone.xpm");
			else if (map->mapstr[y][x] == 'E')
				put_img(map, y, x, "./pic/ball.xpm");
			x++;
		}
		y++;
	}
}
