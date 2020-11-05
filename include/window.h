/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:17:55 by dbegara-          #+#    #+#             */
/*   Updated: 2020/11/04 19:12:01 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#ifndef WINDOW_H
#define WINDOW_H

typedef struct	s_window 
{
	void *mlx;
	void *mlx_win;
}				t_window;

#endif