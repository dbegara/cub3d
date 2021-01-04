/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:43:53 by dbegara-          #+#    #+#             */
/*   Updated: 2021/01/04 21:10:46 by dbegara-         ###   ########.fr       */
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

void    error_exit(char *error, t_g *g, char close)
{
    ft_putstr_fd("Error:\n", 1);
    ft_putstr_fd(error, 1);
    ft_putstr_fd("\n",1);
    if (close)
    {
        printf("Entra\n");
        mlx_destroy_window(g->window.mlx, g->window.mlx_win);
    }
    free_map(g->map);
    free(g);
    system("leaks cub3d");
    exit(1);
}

int     cub_exit(t_g *g)
{
    mlx_destroy_window(g->window.mlx, g->window.mlx_win);
    free_map(g->map);
    free(g);
    system("leaks cub3d");
    exit(0);
}