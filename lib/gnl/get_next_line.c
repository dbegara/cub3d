/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:08:55 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/11 17:58:44 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int		gnl_strlen(char *buffer)
{
	int length;

	length = 0;
	while (buffer[length] != 0)
		length++;
	return (length);
}

int		gnl_check_buff(char *buffer)
{
	int length;

	length = 0;
	while (buffer[length] != '\n' && buffer[length] != 0)
		length++;
	return (length);
}

int		return_func(int rt, char **line)
{
	if (rt == 0)
	{
		*line = gnl_cpybuffer("", *line);
		return (0);
	}
	if (rt < BUFFER_SIZE && rt > 0)
		return (0);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*pr[FD_SIZE];
	int			rt;
	char		buffer[BUFFER_SIZE + 1];

	if (line == NULL)
		return (-1);
	*line = NULL;
	if (pr[fd])
	{
		gnl_memcpy(buffer, pr[fd], gnl_strlen(pr[fd]) + 1);
		free(pr[fd]);
		pr[fd] = NULL;
		*line = gnl_write_line(&pr[fd], buffer, *line, gnl_strlen(buffer));
		if (pr[fd])
			return (1);
	}
	while ((rt = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rt] = 0;
		*line = gnl_write_line(&pr[fd], buffer, *line, rt);
		if (gnl_check_buff(buffer) < rt)
			return (1);
	}
	return (return_func(rt, line));
}
