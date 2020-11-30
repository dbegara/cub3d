/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:17:55 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/30 19:06:15 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#ifndef WINDOW_H
#define WINDOW_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct	s_window 
{
	void *mlx;
	void *mlx_win;
}				t_window;

#endif