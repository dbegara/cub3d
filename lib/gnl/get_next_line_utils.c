/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:53:12 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/11 17:58:55 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*gnl_cpybuffer(char *buffer, char *line)
{
	int		line_size;
	int		buffer_size;
	char	*new;

	if (line)
		line_size = gnl_strlen(line);
	else
		line_size = 0;
	buffer_size = gnl_check_buff(buffer);
	new = malloc(line_size + buffer_size + 1);
	new[line_size + buffer_size] = 0;
	while (buffer_size > 0)
	{
		buffer_size--;
		new[line_size + buffer_size] = buffer[buffer_size];
	}
	while (line_size > 0)
	{
		line_size--;
		new[line_size] = line[line_size];
	}
	free(line);
	return (new);
}

void	*gnl_memcpy(void *restrict dst, const void *restrict src, size_t n)
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

char	*gnl_savepr(char *buffer)
{
	int		offset;
	int		size;
	char	*new;

	offset = gnl_check_buff(buffer) + 1;
	size = gnl_strlen(buffer + offset);
	new = malloc(size + 1);
	new[size] = 0;
	while (size > 0)
	{
		size--;
		new[size] = buffer[size + offset];
	}
	return (new);
}

char	*gnl_write_line(char **pr, char *buffer, char *line, int rt)
{
	if (gnl_check_buff(buffer) == rt)
		line = gnl_cpybuffer(buffer, line);
	if (gnl_check_buff(buffer) < rt)
	{
		line = gnl_cpybuffer(buffer, line);
		*pr = gnl_savepr(buffer);
	}
	return (line);
}
