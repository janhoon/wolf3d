/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:15:25 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:15:26 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		place_char(char **line, int i, int fd)
{
	int	c;

	c = ft_getchar_fd(fd);
	if (c == '\0' || c == '\n')
	{
		line[0][i] = '\0';
		if (c == '\n')
			return (1);
		else if (c == '\0')
		{
			free(line[0]);
			return (0);
		}
	}
	else if (c == -1)
	{
		free(line[0]);
		return (-1);
	}
	else
		line[0][i] = c;
	return (2);
}

int		get_next_line(int fd, char **line)
{
	int			buff;
	static int	i;
	int			test;

	buff = BUFFSIZE;
	i = 0;
	line[0] = malloc(sizeof(char) * buff);
	if (!line[0])
		return (-1);
	while (1)
	{
		test = place_char(&line[0], i, fd);
		if (test != 2)
			return (test);
		i++;
		if (i >= buff)
		{
			buff += BUFFSIZE;
			line[0] = ft_realloc(line[0], buff);
			if (!line[0])
				return (-1);
		}
	}
}
