/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:55:44 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/18 18:30:15 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_window window_init(void)
{
	t_window	window;

	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, WIN_WIDTH, WIN_HEIGHT, "Raycaster");

	return (window);
}