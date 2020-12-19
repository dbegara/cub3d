/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:01:12 by fgarcia-          #+#    #+#             */
/*   Updated: 2020/12/15 21:37:49 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_BONUS_H
# define PRINTF_BONUS_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct		s_tab
{
	const char		*str;
	va_list			args;
	int				length;
	char			*flags;
	char			*types;
	int				left_aligned;
	int				zero_padding;
	int				is_precision;
	size_t			precision;
	size_t			width;
	int				hash;
	int				movistar_plus;
	int				space;
	int				cap_hex;
	int				comma;
	char			*length_flags;
	int				l_type;
	int				ll_type;
	int				h_type;
	int				hh_type;
}					t_tab;

int					ft_printf(const char *format, ...);
char				*ft_add_char(char *out, char c);
void				ft_parse(t_tab *tab);
void				init(t_tab *tab, const char *format);
void				set_default(t_tab *tab);
void				ft_write_char(t_tab *tab, char c);
void				ft_write_str(t_tab *tab, char *brick);
char				*ft_add_str(char *out, char *brick);
char				*ft_puthex(t_tab *tab, intmax_t i, int cap);
char				*ft_precision_str(t_tab *tab, char *arg);
void				ft_parse_type(t_tab *tab);
void				ft_parse_type2(t_tab *tab);
char				*ft_precision_int(t_tab *tab, char *arg);
char				*ft_precision_hex(t_tab *tab, char *arg);
char				*ft_precision_str(t_tab *tab, char *arg);
char				*ft_precision_int_aux(t_tab *tab, char *arg);
char				*ft_add_hash(char *hex, t_tab *tab);
void				ft_width_str(t_tab *tab, char *arg);
void				ft_width_num(t_tab *tab, char *arg);
void				ft_width_hex(t_tab *tab, char *arg);
void				ft_width_aux(t_tab *tab, char *arg, char *padding);
void				ft_width_str_aux(t_tab *tab, char *arg, char *padding);
void				ft_width_hex_aux(t_tab *tab, char *arg, char *padding);
int					char_cmp(char c, char *str);
int					ft_hex_size(intmax_t i);
intmax_t			ft_cast_int(t_tab *tab);
intmax_t			ft_cast_uint(t_tab *tab);
void				ft_arg_to_flag(t_tab *tab, size_t *flag);
void				ft_parse_flags(t_tab *tab);
void				ft_parse_precision(t_tab *tab);
void				ft_parse_length(t_tab *tab);
char				*ft_add_sign(char *num, t_tab *tab);
void				ft_width_char(t_tab *tab, char *arg);
void				ft_width_char_aux(t_tab *tab,
					char *arg, char *padding);
#endif
