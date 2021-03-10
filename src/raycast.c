/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:35:53 by davidbegara       #+#    #+#             */
/*   Updated: 2021/02/22 17:31:37 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	raycast_loop(t_raycast *r, t_g *g, int **world_map)
{
	int color;

	set_vars(r, g);
	ray_calc(r, g);
	ray_dda(r, world_map, g);
	set_vars2(r, g);
	r->step = 1.0 * r->tex_height / r->line_height;
	r->tex_pos = (r->draw_start - g->window.height /
	2 + r->line_height / 2) * r->step;
	r->y = r->draw_start;
	paint_sky(g, r->x, r->draw_start);
	paint_floor(g, r->x, r->draw_end - 1);
	while (r->y <= r->draw_end)
	{
		r->tex_y = (int)r->tex_pos & (r->tex_height - 1);
		r->tex_pos += r->step;
		color = g->texture[tex_num(*r)].
		img.addr[r->tex_height * r->tex_y + r->tex_x];
		img_pixel_put(&g->img, r->x, r->y, color);
		r->y++;
	}
	r->z_buffer[r->x] = r->wall_dist;
	r->x++;
}

void	raycast(int **world_map, t_g *g)
{
	t_raycast r;

	r.z_buffer = malloc(g->window.width * sizeof(double));
	r.x = 0;
	while (r.x < g->window.width)
		raycast_loop(&r, g, world_map);
	r.counter = 0;
	while (r.counter < g->num_sprites)
		order_sprites(&r, g);
	if (g->num_sprites > 1)
		sort_sprites(g);
	if (g->num_sprites)
	{
		r.counter = 0;
		while (r.counter < g->num_sprites)
		{
			set_sprite_vars(&r, g);
			calc_sprite_size(&r, g);
			draw_sprite(&r, g);
			r.counter++;
		}
	}
	free(r.z_buffer);
}
