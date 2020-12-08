/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:11:20 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/14 18:11:23 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	alpha;
	int		cont;
	char	*out;

	out = (char *)s;
	cont = 0;
	alpha = c;
	while (out[cont] != '\0')
		cont++;
	while (cont >= 0)
	{
		if (out[cont] == alpha)
			return (&out[cont]);
		cont--;
	}
	return (0);
}
