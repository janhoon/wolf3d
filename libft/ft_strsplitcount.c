/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitcount.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:15:04 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:15:06 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static char	*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str) + 1))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

t_xcoords	ft_strsplitcount(const char *str, char c)
{
	int			i;
	int			j;
	int			wrd;
	t_xcoords	ret;

	i = 0;
	j = 0;
	wrd = ft_count_words(str, c);
	if (!(ret.coords = (char **)malloc(sizeof(ret.coords) * (wrd + 2))))
		return (ret);
	while (str[i] == c && str[i])
		i++;
	while (j < wrd && str[i])
	{
		ret.coords[j] = ft_word(str, c, &i);
		j++;
	}
	ret.coords[j] = NULL;
	ret.num_coords = wrd;
	return (ret);
}
