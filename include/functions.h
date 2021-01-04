/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:47:43 by dbegara-          #+#    #+#             */
/*   Updated: 2021/01/04 20:54:27 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void        window_init(t_g *g);
void        raycast(char worldMap[24][24], t_g *g);
void		img_pixel_put(t_image *img, int x, int y, int color);
int         pressed(int keycode, t_g *g);
int         depressed(int asi, t_g *me_siento);
void        init_game(t_g *g);
t_player    init_player(void);
int         cub_exit(t_g *g);
int         create_trgb(int r, int g, int b);
int         game_loop(t_g *g);
void        move(t_g *g);
t_texture   xpm_to_img(char *path, t_g *g);
void        paint_sky(t_g *g, int x, int length);
void        paint_floor(t_g *g, int x, int start);
t_g         *check_args(int argc, char **argv);
void        parse_file(char *path, t_g *g);
void        error_exit(char *error, t_g *g, char close);
char        *anti_space(char *str, int skip);
char        *read_line(t_g *g);
int         num_len(char *str);
void        set_res(t_g *g);
int         ft_isspace(char c);
void        init_image(t_g *g);
void        tex_parse(t_g *g);
void        line_error(char *error, t_g *g, char *line);
int         store_num(char *str, int *num);
void        parse_color(t_g *g);
void        map_parse(t_g *g);
void        check_map(t_g *g);
void        find_vecinos(t_map map, int x, int y);

#endif