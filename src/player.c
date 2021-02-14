/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:09:30 by davidbegara       #+#    #+#             */
/*   Updated: 2021/02/14 18:16:38 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_player	init_player(int x, int y, int dx, int dy)
{
	t_player player;

	player.pos_x = x + 0.5;
	player.pos_y = y + 0.5;
	player.dir_x = dx;
	player.dir_y = dy;
	return (player);
}
