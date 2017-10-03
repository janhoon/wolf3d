/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:15:16 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:15:17 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char delim)
{
	static char	*token;
	char		*ptr;
	int			j;
	int			i;

	token = str;
	i = 0;
	ptr = NULL;
	j = 0;
	if (str != NULL)
		token = ft_strdup(str);
	while (*token != '\0' && ++token)
	{
		if (i == 0 && *token != delim)
		{
			i = 1;
			ptr = token;
		}
		else if (i == 1 && *token == delim && ++token)
		{
			token[j] = '\0';
			return (ptr);
		}
	}
	return (ptr);
}
