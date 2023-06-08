/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:40:07 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/09 00:57:27 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    error(int nike)
{
    write(1, "Error\n", 6);
    if (nike == 1)
        write(1, "You must use only one player\n", 28);
    else if (nike == 2)
        write(1, "You must use only one Exit\n", 27);
    else if (nike == 3)
        write(1, "You must use at least one feed\n", 30);
    else
        write(1, "You Wrong\n", )
}
