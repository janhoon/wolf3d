/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:12:49 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:12:50 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ts1;
	const char	*ts2;

	ts1 = (const char *)s1;
	ts2 = (const char *)s2;
	if (n == 0)
	{
		return (0);
	}
	if (ts1 == ts2)
	{
		return (0);
	}
	else
	{
		while (*ts1 == *ts2)
		{
			ts1++;
			ts2++;
		}
		return (*ts2 - *ts1);
	}
	return (0);
}
