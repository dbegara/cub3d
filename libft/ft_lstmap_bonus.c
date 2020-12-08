/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:02:27 by dbegara-          #+#    #+#             */
/*   Updated: 2019/11/20 20:05:05 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;

	if (lst)
	{
		if (!(new_node = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		new_node->next = ft_lstmap(lst->next, f, del);
		return (new_node);
	}
	return (NULL);
}
