/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:02:54 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/24 10:03:06 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*end;

	end = 0;
	c = (char)c;
	while (*str)
	{
		if (*str == c)
		{
			end = (char *) str;
		}
		str++;
	}
	if (!c)
		return ((char *) str);
	return (end);
}
