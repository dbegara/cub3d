/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:59:35 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/25 19:23:33 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	get_player_dir(int *x, int *y, int player)
{
	if (player < 5)
	{
		*y = 0;
		if (player == 3)
			*x = -1;
		else
			*x = 1;
	}
	else
	{
		*x = 0;
		if (player == 5)
			*y = -1;
		else
			*y = 1;
	}
}

void	set_camera_dir(t_g *g)
{
	if (g->player.dir_x > 0)
		g->camera.plane_y = -0.66;
	else if (g->player.dir_x < 0)
		g->camera.plane_y = 0.66;
	else
		g->camera.plane_y = 0;
	if (g->player.dir_y > 0)
		g->camera.plane_x = 0.66;
	else if (g->player.dir_y < 0)
		g->camera.plane_x = -0.66;
	else
		g->camera.plane_x = 0;
}

void	set_player_pos(int i, int j, t_g *g)
{
	int dir_x;
	int dir_y;

	if (g->player.is_player == 1)
		error_exit("Solo puede haber un jugador", g);
	get_player_dir(&dir_x, &dir_y, g->map.w_map[i][j]);
	g->player = init_player(i, j, dir_x, dir_y);
	set_camera_dir(g);
	g->map.w_map[i][j] = 0;
	g->player.is_player = 1;
}

void	get_objects(t_g *g)
{
	int i;
	int j;
	int num_s;

	g->player.is_player = 0;
	num_s = -1;
	i = 0;
	while (i < g->map.height)
	{
		j = 0;
		while (j < g->map.width)
		{
			if (g->map.w_map[i][j] == -1)
				g->map.w_map[i][j] = 0;
			if (g->map.w_map[i][j] > 2)
				set_player_pos(i, j, g);
			if (g->map.w_map[i][j] == 2)
				set_sprite_pos(++num_s, i, j, g);
			j++;
		}
		i++;
	}
	if (!(g->player.is_player))
		error_exit("No hay jugador", g);
}
