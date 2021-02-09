/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:13:17 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:13:17 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*dstc;
	const char	*srcc;

	if (dst == 0 && src == 0)
		return (dst);
	dstc = (char *)dst;
	srcc = (const char *)src;
	while (n > 0)
	{
		*(dstc++) = *(srcc++);
		n--;
	}
	return (dst);
}
