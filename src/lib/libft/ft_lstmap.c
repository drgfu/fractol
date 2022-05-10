/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:13:32 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/22 22:29:41 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_start;

	if (!lst && !f)
		return (NULL);
	new_node = ft_lstnew((*f)(lst->content));
	new_start = new_node;
	while (lst != NULL)
	{
		new_start->next = ft_lstnew((*f)(lst->content));
		if (!new_start->next)
		{
			ft_lstclear(&new_start, del);
			return (NULL);
		}
		lst = lst->next;
		new_start = new_start->next;
	}
	return (new_node);
}
