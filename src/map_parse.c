/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:16:11 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/14 18:30:20 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int		get_int(char c, t_g *g)
{
	if (ft_isspace(c))
		return (0);
	else
	{
		if (c == 'N')
			return (3);
		else if (c == 'S')
			return (4);
		else if (c == 'E')
			return (5);
		else if (c == 'W')
			return (6);
		else if ((c - 48 >= 0 && c - 48 < 3))
			return (c - 48);
		else
		{
			free_textures(g);
			error_exit("Carácter no válido en el mapa", g);
			return (1);
		}
	}
}

void	m_line(int size, char *line, int *map, t_g *g)
{
	int i;

	i = 0;
	while (line[i])
	{
		map[i] = get_int(line[i], g);
		i++;
	}
	while (i < size)
	{
		map[i] = 0;
		i++;
	}
}

void	fill_map(t_g *g, int biggest, int size, t_list *map)
{
	int i;

	i = 0;
	while (i < size)
	{
		g->map.w_map[i] = malloc(biggest * sizeof(int));
		m_line(biggest, map->content, g->map.w_map[i], g);
		map = map->next;
		i++;
	}
}

void	map_parse(t_g *g)
{
	char	*line;
	int		l;
	t_list	*map;

	while ((line = read_line(g)) != 0)
	{
		l = ft_strlen(line);
		if (l > g->map.width)
			g->map.width = l;
		if (g->map.height == 0)
			map = ft_lstnew(line);
		else
			ft_lstadd_back(&map, ft_lstnew(line));
		g->map.height++;
	}
	if (g->map.height < 3 || g->map.width < 3)
	{
		if (g->map.height != 0)
			ft_lstclear(&map, free);
		error_exit("Mapa incorrecto", g);
	}
	g->map.w_map = malloc(g->map.height * sizeof(int *));
	fill_map(g, g->map.width, g->map.height, map);
	ft_lstclear(&map, free);
}
