/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:15:29 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/24 13:24:50 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (!s)
		return (0);
	i = start;
	if (ft_strlen(s) < start)
		return (ft_strdup("\0"));
	while (s[i] != '\0')
		i++;
	if (len > (i - start))
		len = i - start;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(sub_str))
		return (0);
	i = 0;
	while (i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
