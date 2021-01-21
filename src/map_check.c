/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:27:33 by dbegara-          #+#    #+#             */
/*   Updated: 2021/01/07 16:59:47 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    flood_fill(t_map map, int x, int y)
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

void    find_vecinos(t_map map, int x, int y)
{
    flood_fill(map, x+1, y);
    flood_fill(map, x-1, y);
    flood_fill(map, x, y+1);
    flood_fill(map, x, y-1);
}

void    free_textures(t_g *g)
{
    int i;

    i = 0;
    while (i < 4)
    {
        mlx_destroy_image(g->window.mlx, g->texture[i].img.img);
        i++;
    }
    mlx_destroy_image(g->window.mlx, g->sprite.texture.img.img);
}

void    is_open(t_map map, t_g *g)
{
    int i;

    i = 0;
    while (i < map.height)
    {
        if (map.w_map[i][0] == -1 || map.w_map[i][map.width - 1] == -1)
        {
            free_textures(g);
            error_exit("El mapa está abierto", g, 1);
        }
        i++;
    }
    i = 0;
    while (i < map.width)
    {
        if (map.w_map[0][i] == -1 || map.w_map[map.height - 1][i] == -1)
        {
            free_textures(g);
            error_exit("El mapa está abierto", g, 1);
        }
        i++;
    }
}

void    check_map(t_g *g)
{
    int i;
    int j;

    i = 0;
    while (i < g->map.height)
    {
        j = 0;
        while (j < g->map.width)
        {
            if (g->map.w_map[i][j] > 2)
            {
                find_vecinos(g->map, j, i);
                break;
            }
            j++;
        }
        i++;
    }
    is_open(g->map, g);
}