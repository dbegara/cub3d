/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:11:44 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:11:44 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		cont;

	cont = 0;
	if (!s)
		return (0);
	if (!(out = malloc(ft_strlen(s) + 1)))
		return (0);
	while (s[cont] != 0)
	{
		out[cont] = f(cont, s[cont]);
		cont++;
	}
	out[cont] = '\0';
	return (out);
}
