/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:29:36 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/09 20:01:59 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int     num_len(char *str)
{
    int i;

    i = 0;
    while (ft_isdigit(*(str + i)))
        i++;
    return (i);
}

int     ft_isspace(char c)
{
    if (c != ' ' && c != '\n' && c != '\t' 
        && c != '\f' && c != '\v' && c != '\r')
    {
        return (0);
    }
    return (1);
}

int     len_sp(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (*(str + i) != 0)
    {
        if (!(ft_isspace(*(str + i))))
            j++;
        i++;
    }
    return (j);
}

char    *anti_space(char *str, int skip)
{
    int i;
    int len;
    char *new_line;

    i = 0;
    while (ft_isspace(str[i + skip]))
        i++;
    len = ft_strlen(str) - i - skip;
    new_line = malloc(len + 1);
    ft_strlcpy(new_line, str + i + skip, len + 1);
    free(str);
    return (new_line);
}

char    *read_line(t_g *g)
{
    int ret;
    char *line;

    if ((ret = get_next_line(g->file.fd, &line)) <= 0)
    {
        if (ret == 0)
        {
            free(line);
            return (0);
        }
        free(g);
        error_exit("Error\nNo se pudo leer el archivo", g);
    }
    if (len_sp(line) == 0)
    {
        free(line);
        return (read_line(g));
    }
    return (line);
}
