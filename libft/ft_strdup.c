/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:14:26 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:14:28 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (new_str == NULL)
		return (NULL);
	new_str = ft_strcpy(new_str, s1);
	return (new_str);
}
