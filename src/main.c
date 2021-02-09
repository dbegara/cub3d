/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:32:06 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/09 19:43:49 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int		main(int argc, char **argv)
{
	t_g *g;
  
	g = check_args(argc, argv);
	init_game(g);
	mlx_loop_hook(g->window.mlx, game_loop, g);
	mlx_hook(g->window.mlx_win, 2, 1L<<0, pressed, g);
	mlx_hook(g->window.mlx_win, 3, 1L<<1, depressed, g);
	mlx_hook(g->window.mlx_win, EXIT_KEY, 0, cub_exit, g);
	mlx_loop(g->window.mlx);
	return (0);
}