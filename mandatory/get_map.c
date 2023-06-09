/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:56:07 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/15 21:19:23 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*get_map(int fd)
{
	char		*str;
	t_list		*head;
	t_list		*temp;

	head = NULL;
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	while (str)
	{
		temp = ft_lstnew(str);
		ft_lstadd_back(&head, temp);
		str = get_next_line(fd);
	}
	close(fd);
	return (head);
}
