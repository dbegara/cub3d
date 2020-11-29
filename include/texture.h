/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:39:53 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/29 21:15:33 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

#ifndef TEXTURE_H
# define TEXTURE_H

typedef struct  s_texture 
{
    t_image     img;
    int         width;
    int         heigh;
}               t_texture;

#endif