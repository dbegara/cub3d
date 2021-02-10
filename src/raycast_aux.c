/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:15:51 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/10 19:59:50 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	set_vars(t_raycast *r, t_g *g)
{
	r->cam_x = 2 * r->x / (double)g->window.width - 1;
	r->ray_x = g->player.dir_x + g->camera.plane_x * r->cam_x;
	r->ray_y = g->player.dir_y + g->camera.plane_y * r->cam_x;
	r->map_x = (int)g->player.pos_x;
	r->map_y = (int)g->player.pos_y;
	if (r->ray_y == 0)
		r->d_dist_x = 0;
	else if (r->ray_x == 0)
		r->d_dist_x = 1;
	else
		r->d_dist_x = fabs(1 / r->ray_x);
	if (r->ray_x == 0)
		r->d_dist_y = 0;
	else if (r->ray_y == 0)
		r->d_dist_y = 1;
	else
		r->d_dist_y = fabs(1 / r->ray_y);
	r->hit = 0;
}

void	set_vars2(t_raycast *r, t_g *g)
{
	r->line_height = (int)(g->window.height / r->wall_dist);
	r->draw_start = -r->line_height / 2 + g->window.height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + g->window.height / 2;
	if (r->draw_end >= g->window.height)
		r->draw_end = g->window.height - 1;
	r->tex_width = g->texture[0].width;
	r->tex_height = g->texture[0].heigh;
	if (r->side == 0)
		r->wall_x = g->player.pos_y + r->wall_dist * r->ray_y;
	else
		r->wall_x = g->player.pos_x + r->wall_dist * r->ray_x;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * (double)r->tex_width);
	if (r->side == 0 && r->ray_x > 0)
		r->tex_x = r->tex_width - r->tex_x - 1;
	if (r->side == 1 && r->ray_y < 0)
		r->tex_x = r->tex_width - r->tex_x - 1;
}

void	ray_calc(t_raycast *r, t_g *g)
{
	if (r->ray_x < 0)
	{
		r->step_x = -1;
		r->s_dist_x = (g->player.pos_x - r->map_x) * r->d_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->s_dist_x = (r->map_x + 1.0 - g->player.pos_x) * r->d_dist_x;
	}
	if (r->ray_y < 0)
	{
		r->step_y = -1;
		r->s_dist_y = (g->player.pos_y - r->map_y) * r->d_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->s_dist_y = (r->map_y + 1.0 - g->player.pos_y) * r->d_dist_y;
	}
}

void	ray_dda(t_raycast *r, int **world_map, t_g *g)
{
	while (r->hit == 0)
	{
		if (r->s_dist_x < r->s_dist_y)
		{
			r->s_dist_x += r->d_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->s_dist_y += r->d_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (world_map[r->map_x][r->map_y] > 0)
			r->hit = 1;
	}
	if (r->side == 0)
		r->wall_dist = (r->map_x - g->player.pos_x +
		(1 - r->step_x) / 2) / r->ray_x;
	else
		r->wall_dist = (r->map_y - g->player.pos_y +
		(1 - r->step_y) / 2) / r->ray_y;
}

int		tex_num(t_raycast r)
{
	if (r.step_x < 0 && r.side == 0)
		return (0);
	if (r.step_x > 0 && r.side == 0)
		return (1);
	if (r.step_y < 0 && r.side == 1)
		return (2);
	if (r.step_y > 0 && r.side == 1)
		return (3);
	return (0);
}
