# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichan <kichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 16:31:23 by kichan            #+#    #+#              #
#    Updated: 2023/06/16 16:49:57 by kichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ./mandatory
SRC_G = ./gnl
HEADER	=		mandatory/so_long.h

MLX = -L./mlx -lmlx -framework OpenGL -framework Appkit

SRCS =	$(SRC)/error.c \
		$(SRC)/ft_check_arg.c \
		$(SRC)/ft_check_map_two.c \
		$(SRC)/ft_check_map.c \
		$(SRC)/ft_list.c \
		$(SRC)/ft_lookingfor.c \
		$(SRC)/get_map.c \
		$(SRC)/init.c \
		$(SRC)/key.c \
		$(SRC)/main.c \
		$(SRC)/map_download.c \
		$(SRC)/show_map.c \
		$(SRC)/show_walk.c \
		$(SRC_G)/get_next_line.c \
		$(SRC_G)/get_next_line_utils.c \

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C mlx
	
fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

$(NAME):	$(OBJS) $(HEADER)
	make -C mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I. $(MLX)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re