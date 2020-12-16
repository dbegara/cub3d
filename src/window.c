/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:55:44 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/16 19:40:06 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void window_init(t_g *g)
{

	if (g->window.width > MAX_WIN_WIDTH)
		g->window.width = MAX_WIN_WIDTH;
	if (g->window.height > MAX_WIN_HEIGHT)
		g->window.height = MAX_WIN_HEIGHT;
	if (g->window.width < MIN_WIN_WIDTH)
		g->window.width = MIN_WIN_WIDTH;
	if (g->window.height < MIN_WIN_HEIGHT)
		g->window.height = MIN_WIN_HEIGHT;
	g->window.mlx = mlx_init();
	g->window.mlx_win = mlx_new_window(g->window.mlx, g->window.width, g->window.height, "Cub3D");
}