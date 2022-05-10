/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:17:42 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/16 17:33:06 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Parameters #1. The string on which to iterate.
//#2. The function to apply to each character.
//Return value None.
//External functs. None
#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &(s[i]));
		i++;
	}
}
