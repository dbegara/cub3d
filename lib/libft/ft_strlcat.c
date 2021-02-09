/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:12:04 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:12:04 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		dstlen;
	int		srclen;
	int		cont;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= (int)dstsize || dstsize == 0)
		return (dstsize + srclen);
	dstsize = dstsize - dstlen;
	cont = 0;
	while ((dstsize - 1) != 0)
	{
		if (src[cont] != 0)
		{
			dst[cont + dstlen] = src[cont];
			cont++;
		}
		dstsize--;
	}
	dst[cont + dstlen] = 0;
	return (dstlen + srclen);
}
