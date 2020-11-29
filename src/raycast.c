/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:35:53 by davidbegara       #+#    #+#             */
/*   Updated: 2020/11/29 21:25:52 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void raycast(char worldMap[24][24], t_g *g)
{
    int x;

    x = 0;
    while (x < WIN_WIDTH)
    {
        //calculate ray position and direction
        double cameraX = 2 * x / (double)WIN_WIDTH - 1; //x-coordinate in camera space
        double rayDirX = g->player.dir_x + g->camera.plane_x * cameraX;
        double rayDirY = g->player.dir_y + g->camera.plane_y * cameraX;

        //which box of the map we're in
        int mapX = (int)g->player.pos_x;
        int mapY = (int)g->player.pos_y;

        //length of ray from current position to next x or y-side
        double sideDistX;
        double sideDistY;

        //length of ray from one x or y-side to next x or y-side
        double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
        double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
        double perpWallDist;

        //what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;

        int hit = 0; //was there a wall hit?
        int side; //was a NS or a EW wall hit?


        //calculate step and initial sideDist
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (g->player.pos_x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - g->player.pos_x) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (g->player.pos_y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - g->player.pos_y) * deltaDistY;
        }

        //perform DDA
        while (hit == 0)
        {
            //jump to next map square, OR in x-direction, OR in y-direction
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            //Check if ray has hit a wall
            if (worldMap[mapX][mapY] > 0) 
                hit = 1;
        }

        //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
        if(side == 0) 
            perpWallDist = (mapX - g->player.pos_x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - g->player.pos_y + (1 - stepY) / 2) / rayDirY;

        //Calculate height of line to draw on screen
        int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;

        if(drawStart < 0)drawStart = 0;
            int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;

        if(drawEnd >= WIN_HEIGHT)
            drawEnd = WIN_HEIGHT - 1;

        /*
        
        //choose wall color
        int color = create_trgb(0, 200, 150, 150);

        //give x and y sides different brightness
        if(side == 1)
            color = create_trgb(0, 240, 200, 200);

        //draw the pixels of the stripe as a vertical line
        draw_vline(&g->img, x, drawStart, drawEnd, color);

       */

        int text_num = worldMap[mapX][mapY] - 1;
        int tex_width = g->texture[0].width;
        int tex_heigh = g->texture[0].heigh;

        // Calculate where the wall was hit
        double wall_x;
        if (side == 0)
            wall_x = g->player.pos_y + perpWallDist * rayDirY;
        else
            wall_x = g->player.pos_x + perpWallDist * rayDirX;
        wall_x -= floor(wall_x);

        // Calculate x-coordinate on the texture
        int tex_x = (int)(wall_x * (double)tex_width);
        if (side == 0 && rayDirX > 0)
            tex_x = tex_width - tex_x - 1;
        if (side == 1 && rayDirY < 0)
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
            img_pixel_put(&g->img, x, y, color);
            y++;
        }

        paint_sky(&g->img, x, drawStart);
        paint_floor(&g->img, x, drawEnd - 1);

        x++;
    }
}