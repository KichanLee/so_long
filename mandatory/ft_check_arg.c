/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:49:41 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/13 16:36:13 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)ft_strlen_d(s) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void    ft_check_arg(int ac, char **av)
{
    int     i;
    char    *str;

    i = 4;
    if(ac != 2)
        error(4);
    str = ft_strrchr(av[1], '.');
    if(str == NULL || ft_strcmp(str, ".ber") != 0)
        error(4);
}