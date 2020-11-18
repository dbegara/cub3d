/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:09:26 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/18 20:29:18 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	img->addr[y * WIN_WIDTH + x] = color;
}

void	draw_vline(t_image *img, int x, int start, int end, int color)
{
	while(start <= end)
	{
		img_pixel_put(img, x, start, color);
		start++;
	}
}