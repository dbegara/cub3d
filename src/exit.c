/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:43:53 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/23 20:47:53 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int    cub_exit(t_g *g)
{
    mlx_destroy_window(g->window.mlx, g->window.mlx_win);
    free(g);
    system("leaks cub3d");
    exit(0);
}