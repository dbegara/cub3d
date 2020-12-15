/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:04:48 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/15 19:05:58 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_SIZE 4096
# define BUFFER_SIZE 128
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

int		gnl_strlen(char *buffer);
int		gnl_check_buff(char *buffer);
char	*gnl_cpybuffer(char *buffer, char *line);
void	*gnl_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*gnl_savepr(char *buffer);
char	*gnl_write_line(char **pr, char *buffer, char *line, int rt);
int		get_next_line(int fd, char **line);

#endif
