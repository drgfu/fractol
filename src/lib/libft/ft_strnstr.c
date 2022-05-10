/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:15:20 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/28 09:34:05 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a pointer to the first matching instance of string in other string

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*lit == '\0')
		return ((char *)big);
	while (big[i] && len)
	{
		j = 0;
		while (lit[j] && big[j + i] == lit[j] && i + j < len)
		{
			if (lit[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}			
		i++;
	}
	return (0);
}
