/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:05:58 by davidbegara       #+#    #+#             */
/*   Updated: 2021/02/11 17:32:22 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef	struct	s_player
{
	char		is_player;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
}				t_player;

#endif
