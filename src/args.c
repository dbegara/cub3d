/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:07:22 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/15 20:55:42 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_g    *check_args(int argc, char **argv)
{
    t_g *g;

    if (!(g = malloc(sizeof(t_g))))
        error_exit("Error\nFallo al alocar memoria", g, 0);

    g->map.exist = 0;
    if (argc < 2 || argc > 3)
    {
       free(g);
       error_exit("Error\nNúmero de argumentos incorrecto", g, 0);
    }
    while (argc > 1)
    {
        if(!(ft_memcmp(argv[argc - 1], "--save", 7)))
            g->save = 1;
        else
            parse_file(argv[argc - 1], g);
        argc--;
    }
    if (!(g->map.exist))
    {
       free(g);
       error_exit("Error\nNo se ha especificado el .cub", g, 0);
    }
    return (g);
}