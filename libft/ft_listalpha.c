/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:11:54 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:11:55 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		alpha_cmp(char *s1, char *s2)
{
	int		i;
	char	cmp1;
	char	cmp2;

	i = 0;
	cmp1 = 0;
	cmp2 = 0;
	while (s1[++i] != '\0' && cmp1 == 0 && cmp2 == 0)
	{
		if (s1[i] < 123 && s1[i] > 31)
			cmp1 = s1[i] - 30;
		if (s2[i] < 123 && s2[i] > 31)
			cmp1 = s2[i] - 30;
		if (s1[i] < 64 && s1[i] > 31)
			cmp1 = s1[i] - 30;
		if (s2[i] < 64 && s2[i] > 31)
			cmp2 = s2[i] - 30;
		if (s1[i] < 91 && s1[i] > 64)
			cmp1 = s1[i] + 2;
		if (s2[i] < 91 && s2[i] > 64)
			cmp2 = s2[i] + 2;
	}
	if (cmp1 < cmp2)
		return (1);
	return (0);
}

char	**ft_listalpha(char **ls)
{
	int		i;
	char	*temp1;
	char	*temp2;

	i = 0;
	while (ls[i] != '\0')
	{
		if (alpha_cmp(ls[i], ls[i + 1]) == 1)
		{
			temp1 = ls[i];
			temp2 = ls[i + 1];
			ls[i] = ft_realloc(ls[i], sizeof(temp2));
			ls[i + 1] = ft_realloc(ls[i + 1], sizeof(temp1));
			ls = ft_listalpha(ls);
		}
		i++;
	}
	return (ls);
}
