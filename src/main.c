/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:32:06 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/04 20:31:38 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int		main(void)
{
	t_window 	window;
	t_image		img;

	window = window_init();

	img.img = mlx_new_image(window.mlx, 1900, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	img_pixel_put(&img, 900, 540, 0x00FFFFFF);
	img_pixel_put(&img, 900, 541, 0x00FFFFFF);
	img_pixel_put(&img, 900, 542, 0x00FFFFFF);
	img_pixel_put(&img, 900, 543, 0x00FFFFFF);
	img_pixel_put(&img, 900, 544, 0x00FFFFFF);
	img_pixel_put(&img, 900, 545, 0x00FFFFFF);
	mlx_put_image_to_window(window.mlx, window.mlx_win, &img, 0, 0);

	return (0);
}