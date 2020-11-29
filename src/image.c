/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:09:26 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/29 21:24:09 by dbegara-         ###   ########.fr       */
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

void	paint_floor(t_image *img, int x, int start)
{
	while (start++ < WIN_HEIGHT)
		img_pixel_put(img, x, start, create_trgb(0, 50, 60, 80));
}