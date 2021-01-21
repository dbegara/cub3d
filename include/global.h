/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:58:59 by dbegara-          #+#    #+#             */
/*   Updated: 2021/01/07 16:58:37 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#ifndef GLOBAL_H
# define GLOBAL_H

typedef struct  s_map
{
    int         **w_map;
    int         height;
    int         width;
}               t_map;

typedef struct  s_g
{
    char        save;
    int         ceiling;
    int         floor;
    t_map       map;
    t_window    window;
    t_player    player;
    t_camera    camera;
    t_image     img;
    t_move      move;
    t_file      file;
    t_texture   texture[4];
    t_sprite    sprite;
}               t_g;

#endif