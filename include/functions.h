/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:47:43 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/18 20:23:10 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

t_window	window_init(void);
void        raycast(int worldMap[24][24], t_player player, t_camera camera, t_image *img);
void		img_pixel_put(t_image *img, int x, int y, int color);
void	    draw_vline(t_image *img, int x, int start, int end, int color);
t_player    init_player(void);

#endif