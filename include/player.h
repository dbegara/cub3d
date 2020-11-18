/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:05:58 by davidbegara       #+#    #+#             */
/*   Updated: 2020/11/18 20:08:00 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct  s_player 
{
    double      pos_x;
    double      pos_y;
    double      dir_x;
    double      dir_y;
}               t_player;    

#endif