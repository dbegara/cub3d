/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:04:03 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:21:03 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		int_len(int value)
{
	int l;

	l = 1;
	while ((unsigned int)value > 9)
	{
		l++;
		value = value / 10;
	}
	return (l);
}

static char		*reverse_str(char *str, int i, int j)
{
	char c;

	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

char			*ft_itoa(int value)
{
	long	n;
	char	*out;
	int		i;
	int		size;

	if (!(out = malloc(int_len(value) + 1)))
		return (0);
	n = value;
	size = 0;
	if (n < 0)
		n = n * -1;
	i = 0;
	while (n)
	{
		out[i++] = 48 + (n % 10);
		n = n / 10;
		size++;
	}
	if (i == 0)
		out[i++] = '0';
	if (value < 0)
		out[i++] = '-';
	out[i] = '\0';
	return (reverse_str(out, 0, i - 1));
}
