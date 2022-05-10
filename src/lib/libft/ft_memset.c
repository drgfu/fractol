/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:14:14 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/12 19:04:13 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// set n bytes of src to the value of c
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
//#include <stdio.h>
//int main()
//{
//      char    *destination;
//      destination = malloc(100 * sizeof(char));
//      ft_memset(destination, '4', 100);
//      printf("%s\n", destination);
//      ft_memset(destination, '2', 50);
//      printf("%s\n", destination);
//}
