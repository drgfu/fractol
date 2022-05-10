/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:15:12 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/12 20:34:18 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// apply a given function to every char of s
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = ft_calloc(ft_strlen((char *)s) + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
