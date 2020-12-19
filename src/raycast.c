/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:35:53 by davidbegara       #+#    #+#             */
/*   Updated: 2020/12/19 22:02:30 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void set_vars(t_raycast *r, t_g *g)
{
    //calculate ray position and direction
        r->cam_x = 2 * r->x / (double)g->window.width - 1; //x-coordinate in camera space
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

    r.z_buffer = malloc(g->window.width * sizeof(double));
    r.x = 0;
    while (r.x < g->window.width)
    {
        set_vars(&r, g);
        ray_calc(&r, g);
        ray_dda(&r, worldMap, g);

        //Calculate height of line to draw on screen
        int lineHeight = (int)(g->window.height / r.wall_dist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + g->window.height / 2;

        if(drawStart < 0)drawStart = 0;
            int drawEnd = lineHeight / 2 + g->window.height / 2;

        if(drawEnd >= g->window.height)
            drawEnd = g->window.height - 1;

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
        double tex_pos = (drawStart - g->window.height / 2 + lineHeight / 2) * step;
        
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

        paint_sky(g, r.x, drawStart);
        paint_floor(g, r.x, drawEnd - 1);
  
        //Set z_buffer for the sprite
        r.z_buffer[r.x] = r.wall_dist;
        r.x++;
    }

    // SPRITE CASTING
    double sprite_x = g->sprite.x - g->player.pos_x;
    double sprite_y = g->sprite.y - g->player.pos_y;

    double inv_det = 1.0 / (g->camera.plane_x * g->player.dir_y - g->player.dir_x * g->camera.plane_y);

    double trans_x = inv_det * (g->player.dir_y * sprite_x - g->player.dir_x * sprite_y);
    double trans_y = inv_det * (-g->camera.plane_y * sprite_x + g->camera.plane_x * sprite_y);

    int s_screen_x = (int)(g->window.width / 2) * (1 + trans_x / trans_y);

    //calculate height of the sprite on screen
      int spriteHeight = abs((int)(g->window.height / (trans_y))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + g->window.height / 2;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + g->window.height / 2;
      if(drawEndY >= g->window.height) drawEndY = g->window.height - 1;

      //calculate width of the sprite
      int spriteWidth = abs((int)(g->window.height / (trans_y)));
      int drawStartX = -spriteWidth / 2 + s_screen_x;
      if(drawStartX < 0) drawStartX = 0;
        int drawEndX = spriteWidth / 2 + s_screen_x;
      if(drawEndX >= g->window.width) 
        drawEndX = g->window.width - 1;
    for(int stripe = drawStartX; stripe < drawEndX; stripe++)
    {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + s_screen_x)) * g->sprite.texture.width / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(trans_y > 0 && stripe > 0 && stripe < g->window.width && trans_y < r.z_buffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y) * 256 - g->window.height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * g->sprite.texture.heigh) / spriteHeight) / 256;
          int color = g->sprite.texture.img.addr[g->sprite.texture.width * texY + texX]; //get current color from the texture
          if((color & 0x00FFFFFF) != 0) 
            img_pixel_put(&g->img, stripe, y, color); //paint pixel if it isn't black, black is the invisible color
        }
    }
    free(r.z_buffer);
}