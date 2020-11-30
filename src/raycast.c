/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:35:53 by davidbegara       #+#    #+#             */
/*   Updated: 2020/11/30 19:52:36 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void set_vars(t_raycast *r, t_g *g)
{
    //calculate ray position and direction
        r->cam_x = 2 * r->x / (double)WIN_WIDTH - 1; //x-coordinate in camera space
        r->ray_x = g->player.dir_x + g->camera.plane_x * r->cam_x;
        r->ray_y = g->player.dir_y + g->camera.plane_y * r->cam_x;

        //which box of the map we're in
        r->map_x = (int)g->player.pos_x;
        r->map_y = (int)g->player.pos_y;

        //length of ray from one x or y-r.side to next x or y-r.side
        r->d_dist_x = (r->ray_y == 0) ? 0 : ((r->ray_x == 0) ? 1 : fabs(1 / r->ray_x));
        r->d_dist_y = (r->ray_x == 0) ? 0 : ((r->ray_y == 0) ? 1 : fabs(1 / r->ray_y));

        r->hit = 0; //was there a wall r.hit?
}

void    ray_calc(t_raycast *r, t_g *g)
{
        //calculate step and initial r.sideDist
        if (r->ray_x < 0)
        {
            r->step_x = -1;
            r->s_dist_x = (g->player.pos_x - r->map_x) * r->d_dist_x;
        }
        else
        {
            r->step_x = 1;
            r->s_dist_x = (r->map_x + 1.0 - g->player.pos_x) * r->d_dist_x;
        }
        if (r->ray_y < 0)
        {
            r->step_y = -1;
            r->s_dist_y = (g->player.pos_y - r->map_y) * r->d_dist_y;
        }
        else
        {
            r->step_y = 1;
            r->s_dist_y = (r->map_y + 1.0 - g->player.pos_y) * r->d_dist_y;
        }
}

void    ray_dda(t_raycast *r, char worldMap[24][24], t_g *g)
{
    while (r->hit == 0)
    {
        if (r->s_dist_x < r->s_dist_y)
        {
            r->s_dist_x += r->d_dist_x;
            r->map_x += r->step_x;
            r->side = 0;
        }
        else
        {
            r->s_dist_y += r->d_dist_y;
            r->map_y += r->step_y;
            r->side = 1;
        }
        if (worldMap[r->map_x][r->map_y] > 0) 
            r->hit = 1;
    }
    if(r->side == 0) 
       r->wall_dist = (r->map_x - g->player.pos_x + (1 - r->step_x) / 2) / r->ray_x;
    else
        r->wall_dist = (r->map_y - g->player.pos_y + (1 - r->step_y) / 2) / r->ray_y;
}

void    raycast(char worldMap[24][24], t_g *g)
{
    t_raycast r;

    r.x = 0;
    while (r.x < WIN_WIDTH)
    {
        set_vars(&r, g);
        ray_calc(&r, g);
        ray_dda(&r, worldMap, g);

        //Calculate height of line to draw on screen
        int lineHeight = (int)(WIN_HEIGHT / r.wall_dist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;

        if(drawStart < 0)drawStart = 0;
            int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;

        if(drawEnd >= WIN_HEIGHT)
            drawEnd = WIN_HEIGHT - 1;

        int text_num = worldMap[r.map_x][r.map_y] - 1;
        int tex_width = g->texture[0].width;
        int tex_heigh = g->texture[0].heigh;

        // Calculate where the wall was r.hit
        double wall_x;
        if (r.side == 0)
            wall_x = g->player.pos_y + r.wall_dist * r.ray_y;
        else
            wall_x = g->player.pos_x + r.wall_dist * r.ray_x;
        wall_x -= floor(wall_x);

        // Calculate x-coordinate on the texture
        int tex_x = (int)(wall_x * (double)tex_width);
        if (r.side == 0 && r.ray_x > 0)
            tex_x = tex_width - tex_x - 1;
        if (r.side == 1 && r.ray_y < 0)
            tex_x = tex_width - tex_x - 1;

        double step = 1.0 * tex_heigh / lineHeight;
        double tex_pos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;
        
        int y;
        int tex_y;
        y = drawStart;
        while (y < drawEnd)
        {
            tex_y = (int)tex_pos & (tex_heigh - 1);
            tex_pos += step;
            int color = g->texture[text_num].img.addr[tex_heigh * tex_y + tex_x];
            img_pixel_put(&g->img, r.x, y, color);
            y++;
        }

        paint_sky(&g->img, r.x, drawStart);
        paint_floor(&g->img, r.x, drawEnd - 1);

        r.x++;
    }
}