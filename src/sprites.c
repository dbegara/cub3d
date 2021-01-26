/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:13:04 by dbegara-          #+#    #+#             */
/*   Updated: 2021/01/26 18:29:57 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void		set_sprite_pos(int num, int i, int j, t_g *g)
{
    g->sprite[num].x = i;
    g->sprite[num].y = j;
    g->map.w_map[i][j] = 0;
}

void		sprite_malloc(t_g *g)
{
	g->sprite_order = malloc(sizeof(int) * g->num_sprites);
	g->sprite_distance = malloc(sizeof(double) * g->num_sprites);
	g->sprite = malloc(sizeof(t_sprite) * g->num_sprites);
}

void		free_sprites(t_g *g)
{
	free(g->sprite_order);
	free(g->sprite_distance);
	free(g->sprite);
}

void		sort_sprites(t_g *g)
{
	int		i;
	int		j;
	double	dist_tmp;
	int		order_tmp;

	i = 0;
	while (i < g->num_sprites - 1)
	{
		j = 0;
		while (j < g->num_sprites - i - 1)
		{
			if (g->sprite_distance[j] < g->sprite_distance[j + 1])
			{
				dist_tmp = g->sprite_distance[j];
				g->sprite_distance[j] = g->sprite_distance[j + 1];
				g->sprite_distance[j + 1] = dist_tmp;
				order_tmp = g->sprite_order[j];
				g->sprite_order[j] = g->sprite_order[j + 1];
				g->sprite_order[j + 1] = order_tmp;
			}
			j++;
		}
		i++;
	}
}