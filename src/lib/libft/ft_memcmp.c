/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:13:59 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/20 14:32:05 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//      compare the given inputs byte by byte returning 0 if they equal, and a
//      number depending on which of them has a first instance that respectively
//      is bigger or less than the other

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
	{
		return (0);
	}
	while (n)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (*(s1 - 1) - *(s2 - 1));
}
