/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:10:55 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:10:56 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atohex(char c)
{
	if (ft_isdigit(c))
		return ((unsigned int)(c - 48));
	else if (ft_isalpha(c) && c < 'G')
		return ((unsigned int)(c - 55));
	else if (ft_isalpha(c) && c < 'g')
		return ((unsigned int)(c - 87));
	return (0);
}

unsigned int	ft_hextoi(char *str)
{
	unsigned int	ret;
	int				i;

	i = 2;
	ret = 0;
	if (!(str[0] == '0' && str[1] == 'x'))
		return (ret);
	if (ft_ishexa(str[i]))
		ret = ft_atohex(str[i]);
	i++;
	while (str[i] && str[i] != ' ' && ft_ishexa(str[i]))
	{
		ret <<= 4;
		ret += ft_atohex(str[i]);
		i++;
	}
	return (ret);
}
