/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:11:57 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:11:57 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int cont;

	cont = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((dstsize - 1) != 0)
	{
		if (src[cont] != 0)
		{
			dst[cont] = src[cont];
			cont++;
		}
		dstsize--;
	}
	dst[cont] = 0;
	return (ft_strlen(src));
}
