/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 20:25:07 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/17 21:28:57 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    line_error(char *error, t_g *g, char *line)
{
    free(line);
    error_exit(error, g, 1);
}

char    *parse_path(char **line, t_g *g)
{
    int i;
    int len;
    char *path;

    *line = anti_space(*line, 2);
    i = 0;
    while (!(ft_isspace(*(*(line) + i))) && (*(*(line) + i) != 0))
        i++;
    path = malloc(i + 1);
    ft_strlcpy(path, *line, i + 1);
    len = ft_strlen(path);
    if (ft_memcmp(path + (len - 4), ".xpm", 4))
    {
        free(*line);
        line_error("Extensión de textura incorrecto", g, path);
    }
    *line = anti_space(*line, i);
    if (ft_strlen(*line) != 0)
    {
        free(*line);
        line_error("Argumento de textura incorrecto", g, path);
    }
    free(*line);
    return (path);
}

void    tex_parse(t_g *g)
{
    char *line;
    char *texts[4];
    int i;
    
    texts[0] = "NO";
    texts[1] = "SO";
    texts[2] = "WE";
    texts[3] = "EA";
    i = 0;
    while (i < 4)
    {
        line = anti_space(read_line(g), 0);
        if (*line != texts[i][0] || *(line + 1) != texts[i][1] || !(ft_isspace(*(line + 2))))
            line_error("Argumento de textura incorrecto", g, line);
        line = parse_path(&line, g);
        g->texture[i] = xpm_to_img(line, g);
        free(line);
        i++;
    }
    line = anti_space(read_line(g), 0);
    if (*line != 'S' || !(ft_isspace(*(line + 1))))
            line_error("Argumento de sprite incorrecto", g, line);
    line = parse_path(&line, g);
    g->sprite.texture = xpm_to_img(line, g);
    free(line);
}