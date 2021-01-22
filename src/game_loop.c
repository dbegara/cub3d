/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:48:38 by dbegara-          #+#    #+#             */
/*   Updated: 2021/01/22 17:47:40 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int     game_loop(t_g *g)
{
    move(g);
    raycast(g->map.w_map, g);
    mlx_put_image_to_window(g->window.mlx, g->window.mlx_win, g->img.img, 0, 0);
        
    return (0);
}