/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:13:05 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:13:08 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tdest;
	const char	*tsrc;

	tsrc = src;
	tdest = dest;
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	tsrc += n;
	tdest += n;
	while (n--)
		*--tdest = *--tsrc;
	return (dest);
}
