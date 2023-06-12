/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:45:04 by kichlee           #+#    #+#             */
/*   Updated: 2023/06/12 21:49:05 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//void check_square(t_map map)
//{
//    // square인지 확인하는 방법
//    // 1. 한줄씩 돌면서 모두 같은지 
//    // 2. 높이 같은지 
//}


void    ft_check_map(t_map map)
{
    check_square(map);
    check_allowedcharacter(map);
    check_onlyone(map);
    check_dfs(map);
    check_ber(map);

    /**
     *  1. 첫번째, 사각형인지
     *  2. 10CPE 이외의 다른문자가 들어왔는지
     *  3. 1이 사각형을 다 둘러싸고 있는지
     *  4. 예외처리 필요 출구가 없는 경우
     *  5. .ber파일로 만들기
     *  6. shell에 이동횟수 보여주기
     * 
     * */
}