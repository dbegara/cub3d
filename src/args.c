/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:07:22 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/11 16:53:03 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_g		*check_args(int argc, char **argv)
{
	t_g *g;

	if (!(g = malloc(sizeof(t_g))))
	{
		ft_putstr_fd("Error:\nFallo al alocar memoria", 1);
		exit(0);
	}
	g->exit_status = 0;
	g->file.exist = 0;
	if (argc < 2 || argc > 3)
		error_exit("Número de argumentos incorrecto", g);
	while (argc > 1)
	{
		if (!(ft_memcmp(argv[argc - 1], "--save", 7)))
			g->save = 1;
		else
			parse_file(argv[argc - 1], g);
		argc--;
	}
	if (!(g->file.exist))
		error_exit("No se ha especificado el .cub", g);
	return (g);
}
