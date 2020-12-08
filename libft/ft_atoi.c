/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:44:47 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:20:39 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_str_to_num(const char *str, int length, int sign)
{
	int				number;
	int				tmp;
	int				i;

	number = 0;
	while (length > 0)
	{
		tmp = 1;
		i = 1;
		while (length - i != 0)
		{
			tmp = tmp * 10;
			i++;
		}
		number += tmp * (*str - 48);
		str++;
		length--;
	}
	if (sign % 2 != 0)
	{
		number = number * -1;
	}
	return (number);
}

int				ft_atoi(const char *str)
{
	int			sign;
	int			length;
	int			cont;

	sign = 0;
	cont = 0;
	while (str[cont] == ' ' || str[cont] == '\t' ||
	str[cont] == '\n' || str[cont] == '\v' ||
	str[cont] == '\f' || str[cont] == '\r')
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			sign++;
		cont++;
	}
	length = 0;
	while (str[cont + length] <= '9' && str[cont + length] >= '0')
		length++;
	if (length == 0)
		return (0);
	return (ft_str_to_num(&str[cont], length, sign));
}
