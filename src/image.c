/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:09:26 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/16 20:20:25 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	init_image(t_g *g)
{
	g->img.img = mlx_new_image(g->window.mlx, g->window.width, g->window.height);
	g->img.addr = (int *)mlx_get_data_addr(g->img.img, &g->img.bits_per_pixel, &g->img.line_length, &g->img.endian);
    g->img.width = g->window.width;
    g->img.height = g->window.height;
}

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	img->addr[y * img->width + x] = color;
}

void	paint_sky(t_image *img, int x, int length)
{
	while (length-- >= 0)
		img_pixel_put(img, x, length, create_trgb(0, 85, 130, 160));
}

void	paint_floor(t_image *img, int x, int start)
{
	while (start++ < img->height)
		img_pixel_put(img, x, start, create_trgb(0, 50, 60, 80));
}