/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:18:23 by kichan            #+#    #+#             */
/*   Updated: 2023/06/16 16:27:51 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_map
{
	int				width;
	int				height;
	void			*mlx;
	void			*win;
	char			**mapstr;
	int				player[2];
	int				finish[2];
	int				feed;
	int				walkcount;
	struct s_map	*next;
}				t_map;

typedef struct s_check
{
	char			**check_arr_one;
	char			**check_arr_two;
	int				feedcount;
	int				exitcount;
	int				dx[4];
	int				dy[4];
}				t_check;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstclear(t_list **lst);
void			ft_lstclear_map(t_map **lst);
t_list			*get_map(int fd);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			ft_mapdownload(t_map *map, t_list **list);
void			error(int nike);
int				exit_e(void);
void			ft_find_all(t_map *map);
void			ft_find_player(t_map *map);
void			ft_find_feed(t_map *map);
void			ft_find_exit(t_map *map);
void			make_base(t_map *map);
void			put_img(t_map *map, int x, int y, char *file);
void			place_images(t_map *map);
int				key(int key, t_map *map);
void			ft_up(t_map *map);
void			ft_down(t_map *map);
void			ft_left(t_map *map);
void			ft_right(t_map *map);
void			ft_check_map(t_map map, t_map *map_free);
void			check_square(t_map map);
void			check_allowedcharacter(t_map map);
void			check_aroundonlyone(t_map map);
void			ft_check_arg(int ac, char **av);
void			showwalk(t_map *map);
void			for_free(t_check *t, t_map map);
void			init_for_dfs(t_map map);

#endif
