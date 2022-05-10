/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjairus <tjairus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:12:18 by tjairus           #+#    #+#             */
/*   Updated: 2021/09/28 09:53:17 by tjairus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// allocate memory that consists only of '\0' bytes
// The calloc() function allocates memory for an array of nmemb elements 
// of size bytes each and returns a pointer
// to the allocated memory.  The memory is set to zero.  If nmemb or size is  0,
//  then  calloc()  returns  either
// NULL,  or  a  unique  pointer value that can later be successfully passed to 
// free().  If the multiplication of
// nmemb and size would result in integer overflow, then calloc() returns an  
// error.   By  contrast,  an  integer
// overflow  would  not  be detected in the following call to malloc(), with
// the result that an incorrectly sized
// block of memory would be allocated:

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*p;

	p = malloc(nb * size);
	if (!p)
		return (0);
	ft_bzero(p, nb * size);
	return (p);
}
