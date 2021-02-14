/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:27:33 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/14 18:23:57 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	flood_fill(t_map map, int x, int y)
{
	if (x < 0 || x >= map.width || y < 0 || y >= map.height)
		return ;
	if (map.w_map[y][x] != 0)
		return ;
	if (map.w_map[y][x] == -1)
		return ;
	map.w_map[y][x] = -1;
	find_vecinos(map, x, y);
}

void	find_vecinos(t_map map, int x, int y)
{
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	free_textures(t_g *g)
{
	int i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(g->window.mlx, g->texture[i].img.img);
		i++;
	}
	mlx_destroy_image(g->window.mlx, g->sprite_texture.img.img);
}

void	is_open(t_map map, t_g *g)
{
	int i;

	i = 0;
	while (i < map.height)
	{
		if (map.w_map[i][0] == -1 || map.w_map[i][map.width - 1] == -1)
			error_exit("El mapa está abierto", g);
		i++;
	}
	i = 0;
	while (i < map.width)
	{
		if (map.w_map[0][i] == -1 || map.w_map[map.height - 1][i] == -1)
			error_exit("El mapa está abierto", g);
		i++;
	}
}

void	check_map(t_g *g)
{
	int i;
	int j;
	int player;

	i = 0;
	player = 0;
	g->num_sprites = 0;
	while (i < g->map.height)
	{
		j = 0;
		while (j < g->map.width)
		{
			if (g->map.w_map[i][j] > 2 && !player)
			{
				find_vecinos(g->map, j, i);
				player = 1;
			}
			if (g->map.w_map[i][j] == 2)
				g->num_sprites++;
			j++;
		}
		i++;
	}
	is_open(g->map, g);
	sprite_malloc(g);
}
