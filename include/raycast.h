/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:39:15 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/16 19:03:41 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct  s_raycast
{
    double      *z_buffer;
    int         x;
    int         y;
    double      cam_x;
    double      ray_x;
    double      ray_y;
    int         map_x;
    int         map_y;
    double      s_dist_x;
    double      s_dist_y;
    double      d_dist_x;
    double      d_dist_y;
    double      wall_dist;
    int         step_x;
    int         step_y;
    int         hit;
    int         side;
}               t_raycast;

#endif