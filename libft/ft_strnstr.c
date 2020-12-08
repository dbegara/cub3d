/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:11:32 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:11:33 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		conthay;
	int		contnee;

	conthay = 0;
	contnee = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[conthay] != '\0')
	{
		if ((int)len > 0)
		{
			contnee = 0;
			while (haystack[conthay + contnee] == needle[contnee]
			&& ((len - contnee) != 0))
			{
				if (needle[contnee + 1] == '\0')
					return ((char*)&haystack[conthay]);
				contnee++;
			}
		}
		len--;
		++conthay;
	}
	return (0);
}
