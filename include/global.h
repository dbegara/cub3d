/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:58:59 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/23 20:23:35 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#ifndef GLOBAL_H
# define GLOBAL_H

typedef struct  s_g
{
    t_window    window;
    t_player    player;
    t_camera    camera;
    t_image     img;
    t_move      move;
}               t_g;


#endif