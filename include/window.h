/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:17:55 by dbegara-          #+#    #+#             */
/*   Updated: 2021/02/11 17:34:58 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>

# define MAX_WIN_WIDTH 1920
# define MAX_WIN_HEIGHT 1080
# define MIN_WIN_WIDTH 600
# define MIN_WIN_HEIGHT 400

typedef	struct	s_window
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
}				t_window;

#endif
