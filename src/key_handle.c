/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:28:45 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/29 18:35:20 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"
#include <stdio.h>

int     pressed(int keycode, t_g *g)
{
    if (keycode == W_KEY)
        g->move.w = 1;
    else if (keycode == A_KEY)
        g->move.a = 1;
    else if (keycode == S_KEY)
        g->move.s = 1;
    else if (keycode == D_KEY)
        g->move.d = 1;
    else if (keycode == ROT_L_KEY)
        g->move.rot_l = 1;
    else if (keycode == ROT_R_KEY)
        g->move.rot_r = 1;
    else if (keycode == ESC_KEY)
        cub_exit(g);
    return (0);
}

int     depressed(int asi, t_g *me_siento)
{
    if (asi == W_KEY)
        me_siento->move.w = 0;
    else if (asi == A_KEY)
        me_siento->move.a = 0;
    else if (asi == S_KEY)
        me_siento->move.s = 0;
    else if (asi == D_KEY)
        me_siento->move.d = 0;
    else if (asi == ROT_L_KEY)
        me_siento->move.rot_l = 0;
    else if (asi == ROT_R_KEY)
        me_siento->move.rot_r = 0;
    return (0);
}