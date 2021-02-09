/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:23:53 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/09 19:37:18 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	bmp_info_header(unsigned char *bmpinfoheader, t_image *img)
{
	bmpinfoheader[0] = 40;
	bmpinfoheader[4] = (unsigned char)(img->width);
	bmpinfoheader[5] = (unsigned char)(img->width >> 8);
	bmpinfoheader[6] = (unsigned char)(img->width >> 16);
	bmpinfoheader[7] = (unsigned char)(img->width >> 24);
	bmpinfoheader[8] = (unsigned char)(img->height);
	bmpinfoheader[9] = (unsigned char)(img->height >> 8);
	bmpinfoheader[10] = (unsigned char)(img->height >> 16);
	bmpinfoheader[11] = (unsigned char)(img->height >> 24);
	bmpinfoheader[12] = 1;
	bmpinfoheader[14] = img->bits_per_pixel;
}

void	bmp_header(unsigned char *bmpheader, int filesize)
{
	bmpheader[0] = 'B';
	bmpheader[1] = 'M';
	bmpheader[2] = (unsigned char)filesize;
	bmpheader[3] = (unsigned char)(filesize >> 8);
	bmpheader[4] = (unsigned char)(filesize >> 16);
	bmpheader[5] = (unsigned char)(filesize >> 24);
	bmpheader[10] = 54;
}

void	draw_bmp(int file, t_image *img, unsigned int *addr)
{
	int i;
	int j;

	i = img->height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < img->width)
		{
			write(file, &addr[i * img->width + j], 4);
			j++;
		}
		i--;
	}
}

void	img_to_bmp(t_g *g)
{
	int				file;
	int				filesize;
	unsigned char	bmpheader[14];
	unsigned char	bmpinfoheader[40];
	unsigned int	*addr;

	ft_bzero(&bmpheader, 14);
	ft_bzero(&bmpinfoheader, 40);
	filesize = 54 + g->img.width * g->img.height * g->img.bits_per_pixel / 8;
	bmp_header(bmpheader, filesize);
	bmp_info_header(bmpinfoheader, &g->img);
	file = open("./foto.bmp", O_WRONLY | O_CREAT, 0777);
	write(file, bmpheader, 14);
	write(file, bmpinfoheader, 40);
	addr = (unsigned int *)g->img.addr;
	draw_bmp(file, &g->img, addr);
	close(file);
}