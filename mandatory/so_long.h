#ifndef SO_LONG_H
# define SO_LONG_H

// kichan2
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
// kichan
#include <unistd.h>
#include <stdlib.h>
#include "../mlx/mlx.h"
#include "../gnl/get_next_line.h"

// key
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2


typedef struct s_map{

	int		width;
	int		height;
	void	*mlx;
	void	*win;
	char	**mapstr;
	int		player[2];
	int		finish[2];
	int		feed;
}	t_map;
typedef struct s_list
{
	char			*content;
	struct	s_list	*next;
}	t_list;



// ft_list.c
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);


// get_map.c
t_list	*get_map(int fd);

// init.c
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void    ft_mapdownload(t_map *map, t_list **list);

// error.c
void    error(int nike);

// ft_lookingfor.c
void    ft_find_all(t_map *map);
void    ft_find_player(t_map *map);
void    ft_find_feed(t_map *map);
void    ft_find_exit(t_map *map);

// show_map.c
void make_base(t_map *map);
void put_img(t_map *map, int x, int y, char *file);
void	place_images(t_map *map);

// key.c
int     key(int key ,t_map *map);
void    ft_up(t_map *map);
void    ft_down(t_map *map);
void    ft_left(t_map *map);
void    ft_right(t_map *map);

void as(t_map *map);
#endif