/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:09:26 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/25 20:37:16 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	img->addr[y * WIN_WIDTH + x] = color;
}

void	draw_vline(t_image *img, int x, int start, int end, int color)
{
	int y;

	y = 0;
	// Paint sky
	while(y < start)
	{
		img_pixel_put(img, x, y, create_trgb(0, 85, 130, 160));
		y++;
	}
	// Paint wall
	while(start <= end)
	{
		img_pixel_put(img, x, start, color);
		start++;
	}
	// Paint floor
	while(start < WIN_HEIGHT)
	{
		img_pixel_put(img, x, start, create_trgb(0, 50, 60, 80));
		start++;
	}
}