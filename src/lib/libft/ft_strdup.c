/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:14:50 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/22 16:27:23 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// create a duplicate string of s
//#include "libft.h"
#include "libft.h"

// copy n bytes from src to dest and return dest
char	*ft_strdup(const char *s)
{
	char	*copy_s;
	char	*p;
	size_t	i;

	copy_s = 0;
	i = 0;
	while (s[i])
	{
		i++;
	}
	copy_s = malloc((i + 1) * sizeof(char));
	if (!copy_s)
		return (0);
	p = copy_s;
	p = ft_memcpy(p, s, i + 1);
	return (copy_s);
}

//#include <stdio.h>
//
//int main()
//{
//      char    source[] = "Just a random string to check";
//      char    *dest = malloc(100 * sizeof(char));
//	  dest = "This will be gone soon";
//	  printf("%s\n%s\n", source, dest);
//      dest    =       ft_strdup(source);
//      printf("%s\n%s\n", source, dest);
