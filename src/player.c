/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:09:30 by davidbegara       #+#    #+#             */
/*   Updated: 2020/11/18 20:11:58 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_player    init_player(void)
{
    t_player player;

    player.pos_x = 22;
    player.pos_y = 12;  //x and y start position
    player.dir_x = -1;
    player.dir_y = 0; //initial direction vector

    return (player);
}