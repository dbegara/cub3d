/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:47:43 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/04 20:00:59 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

t_window	window_init(void);
t_image		*img_create_tmp(t_image img);
void		img_put_and_destroy(t_window *mlx, t_image *img_prev, t_image *img_new, int x, int y);
void		img_pixel_put(t_image *img, int x, int y, int color);

#endif