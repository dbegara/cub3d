/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:10:50 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/18 19:51:26 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		cont;

	cont = 0;
	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(str = malloc(len + 1)))
		return (0);
	while (len > 0)
	{
		str[cont] = s[start + cont];
		len--;
		cont++;
	}
	str[cont] = '\0';
	return (str);
}
