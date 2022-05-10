/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:14:35 by tjairus           #+#    #+#             */
/*   Updated: 2022/02/23 19:34:28 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		len1;
	int		total_len;
	char	*output;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1) + 1;
	total_len = len1 + ft_strlen(s2);
	output = (char *)malloc(total_len * sizeof(char));
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, (char *)s1, len1);
	ft_strlcat(output, (char *)s2, total_len);
	free(s2);
	free(s1);
	return (output);
}
