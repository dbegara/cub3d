/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:43:53 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/19 21:58:12 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    error_exit(char *error, t_g *g, char close)
{
    ft_putstr_fd("Error:\n", 1);
    ft_putstr_fd(error, 1);
    if (close)
        mlx_destroy_window(g->window.mlx, g->window.mlx_win);
    free(g);
    system("leaks cub3d");
    exit(1);
}

int     cub_exit(t_g *g)
{
    mlx_destroy_window(g->window.mlx, g->window.mlx_win);
    free(g);
    system("leaks cub3d");
    exit(0);
}