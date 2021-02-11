/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:09:26 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/11 17:01:59 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	init_image(t_g *g)
{
	g->img.img = mlx_new_image(g->window.mlx,
	g->window.width, g->window.height);
	g->img.addr = (int *)mlx_get_data_addr(g->img.img,
	&g->img.bits_per_pixel, &g->img.line_length, &g->img.endian);
	g->img.width = g->window.width;
	g->img.height = g->window.height;
}

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	img->addr[y * img->width + x] = color;
}

void	paint_sky(t_g *g, int x, int length)
{
	while (length >= 0)
	{
		img_pixel_put(&g->img, x, length, g->ceiling);
		length--;
	}
}

void	paint_floor(t_g *g, int x, int start)
{
	while (start < g->img.height)
	{
		img_pixel_put(&g->img, x, start, g->floor);
		start++;
	}
}
