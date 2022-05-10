/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:13:28 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/22 22:23:23 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	int		count;
	int		size;

	tmp = lst;
	count = 0;
	size = ft_lstsize(lst);
	if (!lst)
		return (NULL);
	while (count < size - 1)
	{
		tmp = tmp->next;
		count ++;
	}
	return (tmp);
}
