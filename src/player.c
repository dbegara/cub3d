/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:09:30 by davidbegara       #+#    #+#             */
/*   Updated: 2021/02/11 17:14:23 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_player	init_player(int x, int y, int dx, int dy)
{
	t_player player;

	player.pos_x = x;
	player.pos_y = y;
	player.dir_x = dx;
	player.dir_y = dy;
	return (player);
}
