/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:35:53 by davidbegara       #+#    #+#             */
/*   Updated: 2020/11/23 18:52:51 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void raycast(int worldMap[24][24], t_player player, t_camera camera, t_image *img)
{
    int x;

    x = 0;
    while (x < WIN_WIDTH)
    {
        //calculate ray position and direction
        double cameraX = 2 * x / (double)WIN_WIDTH - 1; //x-coordinate in camera space
        double rayDirX = player.dir_x + camera.plane_x * cameraX;
        double rayDirY = player.dir_y + camera.plane_y * cameraX;

        //which box of the map we're in
        int mapX = (int)player.pos_x;
        int mapY = (int)player.pos_y;

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
            sideDistX = (player.pos_x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player.pos_x) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (player.pos_y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player.pos_y) * deltaDistY;
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
            perpWallDist = (mapX - player.pos_x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - player.pos_y + (1 - stepY) / 2) / rayDirY;

        //Calculate height of line to draw on screen
        int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;

        if(drawStart < 0)drawStart = 0;
            int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;

        if(drawEnd >= WIN_HEIGHT)
            drawEnd = WIN_HEIGHT - 1;

        //choose wall color
        int color = 0xFFFFFFF;

        //give x and y sides different brightness
        if(side == 1)
            color = color / 2;

        //draw the pixels of the stripe as a vertical line
        draw_vline(img, x, drawStart, drawEnd, color);
        
        x++;
    }
}