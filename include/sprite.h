/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:00:13 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/03 19:52:18 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#ifndef SPRITE_H
# define SPRITE_H

typedef struct  s_sprite
{
    int         x;
    int         y;
    t_texture   texture;
}               t_sprite;

#endif