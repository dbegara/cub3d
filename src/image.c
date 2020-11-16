/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:09:26 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/04 20:31:36 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_image	*img_create_tmp(t_image img)
{
	t_image		*img_tmp;
	
	img_tmp = malloc(sizeof(t_image));
	
	*img_tmp = img;
	return (img_tmp);
}

void	img_put_and_destroy(t_window *mlx, t_image *img_prev, t_image *img_new, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img_new, x, y);
	mlx_destroy_image(mlx->mlx, img_prev);
}

void	img_pixel_put(t_image *img, int x, int y, int width, int color)
{
	img->addr[x * width + y] = color;
}