/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:14:59 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/20 15:06:03 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	l;
	size_t	m;

	l = 0;
	k = 0;
	m = ft_strlen(dst);
	if (ft_strlen(dst) >= size)
		return (ft_strlen((char *)src) + size);
	while (dst[l])
		l++;
	while (src[k] && (l < (size - 1)))
	{
		dst[l] = src[k];
		l++;
		k++;
	}
	dst[l] = '\0';
	return (m + ft_strlen((char *)src));
}
