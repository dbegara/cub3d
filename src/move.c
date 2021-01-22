/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:25:41 by dbegara-          #+#    #+#             */
/*   Updated: 2021/01/22 19:11:16 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void     move(t_g *g)
{
    double old_dir_x;
    double old_plane_x;

    if (g->move.w)
    {
        if(!(g->map.w_map[(int)(g->player.pos_x + g->player.dir_x * 0.07)][(int)g->player.pos_y]))
            g->player.pos_x += g->player.dir_x * 0.05;
        if(!(g->map.w_map[(int)g->player.pos_x][(int)(g->player.pos_y + g->player.dir_y * 0.07)]))
            g->player.pos_y += g->player.dir_y * 0.05;
    }
    if (g->move.s)
    {
        if(!(g->map.w_map[(int)(g->player.pos_x - g->player.dir_x * 0.07)][(int)g->player.pos_y]))
            g->player.pos_x -= g->player.dir_x * 0.05;
        if(!(g->map.w_map[(int)g->player.pos_x][(int)(g->player.pos_y - g->player.dir_y * 0.07)]))
            g->player.pos_y -= g->player.dir_y * 0.05;
    }
    if (g->move.a)
    {
        if(!(g->map.w_map[(int)(g->player.pos_x - g->player.dir_y * 0.07)][(int)g->player.pos_y]))
            g->player.pos_x -= g->player.dir_y * 0.05;
        if(!(g->map.w_map[(int)g->player.pos_x][(int)(g->player.pos_y + g->player.dir_x * 0.07)]))
            g->player.pos_y += g->player.dir_x * 0.05;
    }
    if (g->move.d)
    {
        if(!(g->map.w_map[(int)(g->player.pos_x + g->player.dir_y * 0.07)][(int)g->player.pos_y]))
            g->player.pos_x += g->player.dir_y * 0.05;
        if(!(g->map.w_map[(int)g->player.pos_x][(int)(g->player.pos_y - g->player.dir_x * 0.07)]))
            g->player.pos_y -= g->player.dir_x * 0.05;
    }
    
    if (g->move.rot_r)
    {
        old_dir_x = g->player.dir_x;
        g->player.dir_x = g->player.dir_x * cos(-0.03) - g->player.dir_y * sin(-0.03);
        g->player.dir_y = old_dir_x * sin(-0.03) + g->player.dir_y * cos(-0.03);
        old_plane_x = g->camera.plane_x;
        g->camera.plane_x = g->camera.plane_x * cos(-0.03) - g->camera.plane_y * sin(-0.03);
        g->camera.plane_y = old_plane_x * sin(-0.03) + g->camera.plane_y * cos(-0.03);
    }
    if (g->move.rot_l)
    {
        old_dir_x = g->player.dir_x;
        g->player.dir_x = g->player.dir_x * cos(0.03) - g->player.dir_y * sin(0.03);
        g->player.dir_y = old_dir_x * sin(0.03) + g->player.dir_y * cos(0.03);
        old_plane_x = g->camera.plane_x;
        g->camera.plane_x = g->camera.plane_x * cos(0.03) - g->camera.plane_y * sin(0.03);
        g->camera.plane_y = old_plane_x * sin(0.03) + g->camera.plane_y * cos(0.03);
    }
}