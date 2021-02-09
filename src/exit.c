/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:43:53 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/09 20:41:58 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    free_map(t_map map)
{
    int i;
    i = 0;
    while (i < map.height)
    {
        free(map.w_map[i]);
        i++;
    }
    free(map.w_map);
}

void    error_exit(char *error, t_g *g)
{
    ft_putstr_fd("Error:\n", 1);
    ft_putstr_fd(error, 1);
    ft_putstr_fd("\n",1);
    cub_exit(g);
}

int     cub_exit(t_g *g)
{
	if (g->exit_status > 0)
	{
		mlx_destroy_window(g->window.mlx, g->window.mlx_win);
		if (g->exit_status > 1)
		{
			free_textures(g);
			if (g->exit_status > 2)
			{
				free_map(g->map);
				if (g->exit_status > 3)
					free_sprites(g);
			}
		}
	}
    free(g);
    system("leaks cub3d");
    exit(0);
}