/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:16:11 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/20 20:57:08 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void    map_parse(t_g *g)
{
    char    *line;
    int     biggest;
    int     len;
    int     i;
    t_list  *map;

    biggest = 0;
    i = 0;
    while ((len = get_next_line(g->file.fd, &line)) > 0)
    {
        if (len > biggest)
            biggest = len;
        if (i == 0)
            map = ft_lstnew(line);
        else
            ft_lstadd_back(&map, ft_lstnew(line));
        i++;
    }
}