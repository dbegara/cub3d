/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:24:24 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/16 21:25:08 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    init_game(t_g *g)
{
    window_init(g);
    init_image(g);
	g->player = init_player();

	g->camera.plane_x = 0;
	g->camera.plane_y = 0.66;

    g->move.a = 0;
    g->move.w = 0;
    g->move.d = 0;
    g->move.s = 0;

    g->move.rot_l = 0;
    g->move.rot_r = 0;

    load_textures(g);
}