/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:47:43 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/15 20:49:45 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

t_window	window_init(void);
void        raycast(char worldMap[24][24], t_g *g);
void		img_pixel_put(t_image *img, int x, int y, int color);
int         pressed(int keycode, t_g *g);
int         depressed(int asi, t_g *me_siento);
void        init_game(t_g *g);
t_player    init_player(void);
int         cub_exit(t_g *g);
int         create_trgb(int t, int r, int g, int b);
int         game_loop(t_g *g);
void        move(t_g *g);
t_texture   xpm_to_img(char *path, t_g *g);
void        load_textures(t_g *g);
void        paint_sky(t_image *img, int x, int length);
void        paint_floor(t_image *img, int x, int start);
t_g         *check_args(int argc, char **argv);
void        parse_file(char *path, t_g *g);
void        error_exit(char *error, t_g *g, char close);

#endif