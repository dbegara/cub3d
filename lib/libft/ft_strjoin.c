/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:12:12 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/18 19:49:06 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		total_len;
	int		cont;
	int		cont2;

	if (s1 == 0 || s2 == 0)
		return (0);
	cont = 0;
	cont2 = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(total_len + 1)))
		return (0);
	while (s1[cont] != '\0')
	{
		str[cont] = s1[cont];
		cont++;
	}
	while (s2[cont2] != '\0')
	{
		str[cont + cont2] = s2[cont2];
		cont2++;
	}
	str[cont + cont2] = '\0';
	return (str);
}
