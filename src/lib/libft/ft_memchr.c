/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:13:54 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/16 09:26:35 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a pointer to the first instance of c in the s, checking only n bytes
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
//int main()
//{
//      char    test[] = "abcdefghijklmnopqrstuvwxyz0123456789";
//      char    *c_pos;
//      char    c = 'v';
//      c_pos = ft_memchr(test, c, 36);
//      write(1, &c, 1);
//      write(1, "\t", 1);
//      write(1, c_pos, 12);
//}
