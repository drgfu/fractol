/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:14:44 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/24 10:03:27 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return a pointer to the first instance of c in str
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*f;

	f = (unsigned char *)s;
	i = 0;
	c = (char)c;
	while (f[i])
	{
		if (f[i] == c)
			return ((char *)(f + i));
		i++;
	}
	if (f[i] == c)
		return ((char *)(f + i));
	return (NULL);
}
//int main()
//{
//              char    test[] = "abcdefghijklmnopqrstuvwxyz0123456789";
//      char    *pc;
//      char    c = 'e';
//      pc = ft_strchr(test, c);
//      write(1, &c, 1);
//      write(1, "\t", 1);
//      write(1, pc, 10);     
//}
