/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:09:26 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/26 18:47:03 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	img->addr[y * WIN_WIDTH + x] = color;
}

void	paint_sky(t_image *img, int x, int length)
{
	while (length-- >= 0)
		img_pixel_put(img, x, length, create_trgb(0, 85, 130, 160));
}

void	paint_wall(t_image *img, int x, int start, int end, int color)
{
	while (start <= end)
	{
		img_pixel_put(img, x, start, color);
		start++;
	}
}

void	paint_floor(t_image *img, int x, int start)
{
	while (start++ < WIN_HEIGHT)
		img_pixel_put(img, x, start, create_trgb(0, 50, 60, 80));
}

void	draw_vline(t_image *img, int x, int start, int end, int color)
{
	paint_sky(img, x, start);

	paint_wall(img, x, start, end, color);
	
	paint_floor(img, x, end);
}