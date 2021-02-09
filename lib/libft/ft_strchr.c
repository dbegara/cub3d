/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:12:23 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:12:24 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	alpha;
	int		cont;
	char	*out;

	out = (char *)s;
	alpha = c;
	cont = 0;
	if (c == 0)
		return (&out[ft_strlen(s)]);
	while (out[cont] != 0)
	{
		if (out[cont] == alpha)
			return (&out[cont]);
		cont++;
	}
	return (0);
}
