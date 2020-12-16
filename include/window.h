/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:17:55 by dbegara-          #+#    #+#             */
/*   Updated: 2020/12/16 19:39:23 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#ifndef WINDOW_H
#define WINDOW_H

# define MAX_WIN_WIDTH 1920
# define MAX_WIN_HEIGHT 1080
# define MIN_WIN_WIDTH 100
# define MIN_WIN_HEIGHT 100

typedef struct	s_window 
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
}				t_window;

#endif