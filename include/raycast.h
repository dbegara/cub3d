/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:39:15 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/11 17:32:43 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

typedef	struct	s_raycast
{
	int			counter;
	double		*z_buffer;
	int			x;
	int			y;
	double		cam_x;
	double		ray_x;
	double		ray_y;
	int			map_x;
	int			map_y;
	double		s_dist_x;
	double		s_dist_y;
	double		d_dist_x;
	double		d_dist_y;
	double		wall_dist;
	double		wall_x;
	double		step;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_width;
	int			tex_height;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		trans_x;
	double		trans_y;
	int			s_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_y;
	int			draw_start_x;
	int			draw_end_y;
	int			draw_end_x;
	int			stripe;
}				t_raycast;

#endif
