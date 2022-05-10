/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:14:55 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/12 19:19:13 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// concatenate two strings into one new string
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_length;
	size_t	length_dst;
	size_t	length_src;
	char	*res;

	length_dst = ft_strlen((char *)s1);
	length_src = ft_strlen((char *)s2);
	total_length = length_src + length_dst;
	res = malloc(total_length + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, length_dst + 1);
	ft_strlcpy(&res[(length_dst)], s2, length_src + 1);
	return (res);
}
//#include <stdio.h>
//int main()
//{
//      char    first[] = "First";
//      char    second[] = "&second";
//      printf("%s\n%s\n%s\n", first, second, ft_strjoin(first, second));
//}
