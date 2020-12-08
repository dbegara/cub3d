/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:49:39 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/20 21:01:46 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*element;
	t_list		*tmp;

	element = *lst;
	while (element)
	{
		tmp = element->next;
		ft_lstdelone(element, del);
		element = tmp;
	}
	*lst = NULL;
}
