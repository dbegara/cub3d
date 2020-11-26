/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:24:24 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/26 18:24:26 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    init_game(t_g *g)
{
    g->window = window_init();
	g->player = init_player();

	g->camera.plane_x = 0;
	g->camera.plane_y = 0.66;

	g->img.img = mlx_new_image(g->window.mlx, WIN_WIDTH, WIN_HEIGHT);
	g->img.addr = (int *)mlx_get_data_addr(g->img.img, &g->img.bits_per_pixel, &g->img.line_length, &g->img.endian);

    g->move.a = 0;
    g->move.w = 0;
    g->move.d = 0;
    g->move.s = 0;

    g->move.rot_l = 0;
    g->move.rot_r = 0;
}