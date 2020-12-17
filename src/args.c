/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:07:22 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/17 19:26:04 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_g    *check_args(int argc, char **argv)
{
    t_g *g;

    if (!(g = malloc(sizeof(t_g))))
        error_exit("Fallo al alocar memoria", g, 0);
    g->file.exist = 0;
    if (argc < 2 || argc > 3)
       error_exit("Número de argumentos incorrecto", g, 0);
    while (argc > 1)
    {
        if(!(ft_memcmp(argv[argc - 1], "--save", 7)))
            g->save = 1;
        else
            parse_file(argv[argc - 1], g);
        argc--;
    }
    if (!(g->file.exist))
       error_exit("No se ha especificado el .cub", g, 0);
    return (g);
}