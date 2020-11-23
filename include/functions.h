/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:47:43 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/23 20:47:44 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

t_window	window_init(void);
void        raycast(int worldMap[24][24], t_player player, t_camera camera, t_image *img);
void		img_pixel_put(t_image *img, int x, int y, int color);
void	    draw_vline(t_image *img, int x, int start, int end, int color);
int         pressed(int keycode, t_g *g);
int         depressed(int asi, t_g *me_siento);
void        init_game(t_g *g);
t_player    init_player(void);
int         cub_exit(t_g *g);

#endif