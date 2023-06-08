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

#endif