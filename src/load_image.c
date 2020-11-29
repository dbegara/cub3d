/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:11:59 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/29 21:16:45 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_texture   xpm_to_img(char *path, t_g *g)
{
    t_texture texture;

    texture.img.img = mlx_xpm_file_to_image(g->window.mlx, path, &texture.width, &texture.heigh);
    texture.img.addr = (int *)mlx_get_data_addr(texture.img.img, &texture.img.bits_per_pixel, &texture.img.line_length, &texture.img.endian);

    return (texture);
}