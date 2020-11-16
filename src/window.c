/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:55:44 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/04 20:01:45 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

t_window window_init(void)
{
	t_window	window;

	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello World");

	return (window);
}