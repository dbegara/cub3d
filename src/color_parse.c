/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:19:28 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/19 21:21:42 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int     retrieve_number(char **line, t_g *g, int i)
{
    int num;
    int num_len;
    
    if (!ft_isdigit(**line))
        line_error("Parametro de color incorrecto2", g, *line);
    num_len = store_num(*line, &num);
    if (i != 2)
        *line = anti_space(*line, num_len);
    if (**line != ',' && i != 2)
        line_error("Parametro de color incorrecto3", g, *line);
    if (i != 2)
        *line = anti_space(*line, 1);
    if (i == 2 && ft_strlen(*(line) + num_len) != 0)
        line_error("Parametro de color incorrecto4", g, *line);
    return (num);
}

int     get_color(char **line, t_g *g)
{
    int color[3];
    int i;

    i = 0;
    while (i < 3)
    {
        color[i] = retrieve_number(line, g, i);
        printf("\n %d \n", color[i]);
        i++;
    }
    fflush(stdout);
    return (create_trgb(color[0], color[1], color[2]));
}

void    parse_color(t_g *g)
{
    char *line;

    line = anti_space(read_line(g), 0);
    if (*line != 'C')
        line_error("Parametro de color incorrecto1", g, line);
    line = anti_space(line, 1);
    g->ceiling = get_color(&line, g);
    free(line);
    line = anti_space(read_line(g), 0);
    if (*line != 'F')
        line_error("Parametro de color incorrecto", g, line);
    line = anti_space(line, 1);
    g->floor = get_color(&line, g);
    free(line);
}