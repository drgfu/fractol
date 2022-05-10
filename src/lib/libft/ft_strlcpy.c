/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:15:03 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/12 20:41:10 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy size bytes from src to dest, overwriting dest
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1) < size)
	{
		if (!(size == 0))
			dst[i] = src[i];
		i++;
	}
	if (!(size == 0))
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}
