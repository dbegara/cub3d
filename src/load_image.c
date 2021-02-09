/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:11:59 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/09 20:37:31 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_texture   xpm_to_img(char *path, t_g *g)
{
    t_texture texture;

    if (!(texture.img.img = mlx_xpm_file_to_image(g->window.mlx, path, &texture.width, &texture.heigh)))
        error_exit("No se pudo cargar la textura", g);
    if (!(texture.img.addr = (int *)mlx_get_data_addr(texture.img.img, &texture.img.bits_per_pixel, &texture.img.line_length, &texture.img.endian)))
        error_exit("No se pudo cargar la textura", g);
    return (texture);
}