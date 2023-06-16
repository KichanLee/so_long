/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:05:18 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/16 16:11:53 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*curr;
	t_list	*next;

	if (!lst)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

void	ft_lstclear_map(t_map **lst)
{
	t_map	*curr;
	t_map	*next;

	if (!lst)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lkc;

	lkc = *lst;
	if (!lst)
		return ;
	else if (!(*lst))
		(*lst) = new;
	else
	{
		while ((*lst)-> next)
			(*lst) = (*lst)-> next;
		(*lst)-> next = new;
		(*lst) = lkc;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list -> content = content;
	list -> next = NULL;
	return (list);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst -> next;
		++count;
	}
	return (count);
}
