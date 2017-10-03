/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:12:19 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:12:23 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char	*tsrc;
	char		*tdest;
	int			i;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	tdest = (char *)dest;
	tsrc = (const char *)src;
	while (*tsrc && --n)
		if (*tsrc == c)
			i = 1;
	if (i == 0)
		return (NULL);
	while (n-- && *tsrc != c)
	{
		*tdest = *tsrc;
		if (n)
		{
			tdest++;
			tsrc++;
		}
	}
	return (dest);
}
