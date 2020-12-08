/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:47:51 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:13:59 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
const void *restrict src, int c, size_t n)
{
	unsigned char	*dstc;
	unsigned char	*srcc;

	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	while (n > 0)
	{
		if (*srcc == (unsigned char)c)
		{
			*(dstc++) = *(srcc++);
			return (dstc);
		}
		*(dstc++) = *(srcc++);
		n--;
	}
	return (0);
}
