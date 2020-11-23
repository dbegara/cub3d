/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:28:45 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/23 20:59:04 by dbegara-         ###   ########.fr       */
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
    else if (keycode == ESC_KEY)
        cub_exit(g);
    return (0);
}

int     depressed(int asi, t_g *me_siento)
{
    if (asi == W_KEY)
        me_siento->move.w = 1;
    else if (asi == A_KEY)
        me_siento->move.a = 1;
    else if (asi == S_KEY)
        me_siento->move.s = 1;
    else if (asi == D_KEY)
        me_siento->move.d = 1;
    return (0);
}