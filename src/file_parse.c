/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:44:21 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/22 17:42:48 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	check_file_name(char *path, t_g *g)
{
	int len;

	len = ft_strlen(path);
	if (ft_memcmp(path + (len - 4), ".cub", 4) || g->file.exist)
		error_exit("Argumento incorrecto", g);
	g->file.exist = 1;
	g->file.path = path;
}

void	open_file(t_g *g)
{
	if ((g->file.fd = open(g->file.path, O_RDONLY)) < 0)
		error_exit("No se ha encontrado el .cub", g);
}

void	parse_file(char *path, t_g *g)
{
	check_file_name(path, g);
	open_file(g);
	set_res(g);
	window_init(g);
	tex_parse(g);
	g->exit_status = 2;
	parse_color(g);
	g->map.height = 0;
	g->map.width = 0;
	map_parse(g);
	g->exit_status = 3;
	check_map(g);
	g->exit_status = 4;
	get_objects(g);
}
