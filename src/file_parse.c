/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:44:21 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/17 21:24:14 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/includes.h"

void    check_file_name(char *path, t_g *g)
{
    int len;

    len = ft_strlen(path);
    if (ft_memcmp(path + (len - 4), ".cub", 4) || g->file.exist)
        error_exit("Error\nArgumento incorrecto", g, 0);
    g->file.exist = 1;
    g->file.path = path;
}

void    open_file(t_g *g)
{
    if ((g->file.fd = open(g->file.path, O_RDONLY)) < 0)
        error_exit("No se ha encontrado el .cub", g, 0);
}

void    parse_file(char *path, t_g *g)
{
    check_file_name(path, g);
    open_file(g);
    set_res(g);
    window_init(g);
    tex_parse(g);
}