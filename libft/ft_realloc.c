/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:21:20 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:21:21 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t n)
{
	char	*nptr;

	if (!n && ptr)
	{
		if (!(nptr = (char *)malloc(1)))
			return (NULL);
		free(ptr);
		return (nptr);
	}
	if (!(nptr = (char *)malloc(n)))
	{
		return (NULL);
	}
	if (ptr)
	{
		ft_memcpy(nptr, ptr, n);
		free(ptr);
	}
	return (nptr);
}
