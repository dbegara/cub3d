/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:19:28 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/17 20:43:33 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    check_number(char c, t_g *g, char *line)
{
    if (!ft_isdigit(c))
        line_error("Parámetro de color incorrecto", g, line);
}

void    save_color(int *color, char **line, t_g *g, char last)
{
    int num_len;

    check_number(**line, g, *line);
    //num_len = store_num(*line, color);
    num_len = *color;
    //if (*(*(line) + num_len + 1) != (',' | ' ') && !last)
    //line_error("TESTParámetro de color incorrecto", g, *line);
    printf("Line: %s\nnum_len: %d\n", *line, num_len);
    system("leaks cub3d");
    exit(1);
    *line = anti_space(*line, num_len + 1);
    if (last && ft_strlen(*line) != 0)
        line_error("Parámetro de color incorrecto", g, *line);
}

void    check_param(t_g *g, char c)
{
    char    *line;
    /*int     c_r;
    int     c_g;
    int     c_b;*/
    c = 0;
    line = malloc(9);
    //line = anti_space(read_line(g), c);
    printf("Puntero: %p", line);
    fflush(stdout);
    //if (*line != c || !(ft_isspace(*(line + 1))))
        line_error("Parámetro de color incorrecto", g, line);
    /*line = anti_space(line, 1);
    save_color(&c_r, &line, g, 0);
    save_color(&c_g, &line, g, 0);
    save_color(&c_b, &line, g, 1);
    if (((c_r | c_g | c_b) > 255) || ((c_r | c_g | c_b) < 0))
        line_error("Parámetro de color incorrecto", g, line);
    free(line);
    return (create_trgb(0, c_r, c_g, c_b));*/
}

void    parse_color(t_g *g)
{
    check_param(g, 'C');
    //g->floor = check_param(g, 'F');
}