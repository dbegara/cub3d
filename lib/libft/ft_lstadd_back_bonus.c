/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:02:29 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/20 17:40:30 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last_list;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		last_list = ft_lstlast(*alst);
		last_list->next = new;
	}
}
