/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:14:39 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/20 15:12:49 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (*(s + i))
	{
		if (*(s + i) && *(s + (i + 1)) != c && (s + (i + 1)))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		start;
	int		end;
	char	**string;

	if (!str)
		return (NULL);
	i = 0;
	start = 0;
	string = ft_calloc(ft_count((char *)str, c) + 1, sizeof(char *));
	if (!string)
		return (NULL);
	while (*(str + start))
	{
		while (*(str + start) == c && *(str + start))
			start++;
		end = start;
		while (*(str + end) != c && *(str + end))
			end++;
		if (*(str + start))
			string[i] = ft_substr(str, start, end - start);
		i++;
		start = end;
	}
	return (string);
}
