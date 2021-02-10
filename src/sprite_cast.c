/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:34:18 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/10 20:04:50 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	set_sprite_vars(t_raycast *r, t_g *g)
{
	r->sprite_x = g->sprite[g->sprite_order[r->counter]].x - g->player.pos_x;
	r->sprite_y = g->sprite[g->sprite_order[r->counter]].y - g->player.pos_y;
	r->inv_det = 1.0 / (g->camera.plane_x * g->player.dir_y -
	g->player.dir_x * g->camera.plane_y);
	r->trans_x = r->inv_det * (g->player.dir_y * r->sprite_x
	- g->player.dir_x * r->sprite_y);
	r->trans_y = r->inv_det * (-g->camera.plane_y * r->sprite_x
	+ g->camera.plane_x * r->sprite_y);
	r->s_screen_x = (int)(g->window.width / 2) * (1 + r->trans_x / r->trans_y);
}

void	order_sprites(t_raycast *r, t_g *g)
{
	g->sprite_order[r->counter] = r->counter;
	g->sprite_distance[r->counter] =
	((g->player.pos_x - g->sprite[r->counter].x) *
	(g->player.pos_x - g->sprite[r->counter].x) +
	(g->player.pos_y - g->sprite[r->counter].y) *
	(g->player.pos_y - g->sprite[r->counter].y));
	r->counter++;
}

void	calc_sprite_size(t_raycast *r, t_g *g)
{
	r->sprite_height = abs((int)(g->window.height / (r->trans_y)));
	r->draw_start_y = -r->sprite_height / 2 + g->window.height / 2;
	if (r->draw_start_y < 0)
		r->draw_start_y = 0;
	r->draw_end_y = r->sprite_height / 2 + g->window.height / 2;
	if (r->draw_end_y >= g->window.height)
		r->draw_end_y = g->window.height - 1;
	r->sprite_width = abs((int)(g->window.height / (r->trans_y)));
	r->draw_start_x = -r->sprite_height / 2 + r->s_screen_x;
	if (r->draw_start_x < 0)
		r->draw_start_x = 0;
	r->draw_end_x = r->sprite_width / 2 + r->s_screen_x;
	if (r->draw_end_x >= g->window.width)
		r->draw_end_x = g->window.width - 1;
}

void	draw_sprite(t_raycast *r, t_g *g)
{
	int	y;
	int	d;
	int	color;

	r->stripe = r->draw_start_x - 1;
	while (++r->stripe < r->draw_end_x)
	{
		r->tex_x = (int)(256 * (r->stripe - (-r->sprite_width / 2 +
		r->s_screen_x)) * g->sprite_texture.width / r->sprite_width) / 256;
		if (r->trans_y > 0 && r->stripe > 0 && r->stripe < g->window.width
		&& r->trans_y < r->z_buffer[r->stripe])
		{
			y = r->draw_start_y - 1;
			while (++y < r->draw_end_y)
			{
				d = (y) * 256 - g->window.height * 128 + r->sprite_height * 128;
				r->tex_y = ((d * g->sprite_texture.heigh)
				/ r->sprite_height) / 256;
				color = g->sprite_texture.img.addr[g->sprite_texture.width
				* r->tex_y + r->tex_x];
				if ((color & 0x00FFFFFF) != 0)
					img_pixel_put(&g->img, r->stripe, y, color);
			}
		}
	}
}
