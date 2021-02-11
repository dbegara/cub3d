/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:55:09 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/11 17:15:21 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	res_error(char *error, t_g *g, char *line)
{
	free(line);
	error_exit(error, g);
}

int		store_num(char *str, int *num)
{
	int		len;
	char	*a_num;

	len = num_len(str);
	a_num = malloc(len + 1);
	ft_strlcpy(a_num, str, len + 1);
	*num = atoi(a_num);
	free(a_num);
	return (len);
}

void	set_res(t_g *g)
{
	char *line;

	line = anti_space(read_line(g), 0);
	if (*line != 'R' || !(ft_isspace(*(line + 1))))
		res_error("Parametro resolución incorrecto", g, line);
	line = anti_space(line, 1);
	if (!ft_isdigit(*line))
		res_error("Parametro resolución incorrecto", g, line);
	line = anti_space(line, store_num(line, &g->window.width));
	if (!ft_isdigit(*line))
		res_error("Parametro resolución incorrecto", g, line);
	line = anti_space(line, store_num(line, &g->window.height));
	if (ft_strlen(line) != 0)
		res_error("Parametro resolución incorrecto", g, line);
	free(line);
}
