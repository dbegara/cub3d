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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define IMG_WIDTH 400
# define IMG_HEIGHT 300

int		main(void)
{
	t_window 	window;
	t_image		img;
	int		count_w;
	int		count_h;

	window = window_init();

	img.img = mlx_new_image(window.mlx, IMG_WIDTH, IMG_HEIGHT);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (count_w % 2)
				img_pixel_put(&img, count_h, count_w, IMG_WIDTH, 0xFFFFFF);
			else
				img_pixel_put(&img, count_h, count_w, IMG_WIDTH, 0xFF0000);
		}
	}

	mlx_put_image_to_window(window.mlx, window.mlx_win, img.img, 0, 0);
	mlx_loop(window.mlx);
	return (0);
}