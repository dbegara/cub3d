/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:58:59 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/11 17:33:29 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "includes.h"

typedef	struct	s_map
{
	int			**w_map;
	int			height;
	int			width;
}				t_map;

typedef	struct	s_g
{
	char		save;
	char		exit_status;
	t_map		map;
	t_window	window;
	t_player	player;
	t_camera	camera;
	t_image		img;
	t_move		move;
	t_file		file;
	t_texture	texture[4];
	t_texture	sprite_texture;
	int			ceiling;
	int			floor;
	int			num_sprites;
	int			*sprite_order;
	double		*sprite_distance;
	t_sprite	*sprite;
}				t_g;

#endif
