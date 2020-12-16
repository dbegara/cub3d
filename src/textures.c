/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:53:50 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/16 21:25:17 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    load_textures(t_g *g)
{
    //Sprite texture
    g->sprite.texture = xpm_to_img("textures/sprite.xpm", g);
    g->sprite.x = 7;
    g->sprite.y = 11;
}