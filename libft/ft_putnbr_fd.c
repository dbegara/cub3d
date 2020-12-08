/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:44:20 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/13 14:44:21 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = i * -1;
	}
	if (i < 10)
	{
		ft_putchar_fd('0' + i, fd);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd('0' + i % 10, fd);
	}
	return ;
}
