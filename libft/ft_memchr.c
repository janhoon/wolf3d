/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:12:36 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:12:40 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ts;

	i = 0;
	ts = (unsigned char *)s;
	if (s && n > 0)
	{
		while (ts[i] == (unsigned char)c)
			return ((void *)(ts + i));
		i++;
	}
	return (NULL);
}
