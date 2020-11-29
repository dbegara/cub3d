/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:53:50 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/29 20:45:27 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    load_textures(t_g *g)
{
    g->texture[0] = xpm_to_img("textures/wall1.xpm", g);
    g->texture[1] = xpm_to_img("textures/wall2.xpm", g);
    g->texture[2] = xpm_to_img("textures/wall3.xpm", g);
    g->texture[3] = xpm_to_img("textures/wall4.xpm", g);
}