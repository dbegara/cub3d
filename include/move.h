/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:21:26 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/25 20:38:47 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

typedef struct  s_move
{
    int         w;
    int         s;
    int         a;
    int         d;
    int         rot_l;
    int         rot_r;
}               t_move;


#endif