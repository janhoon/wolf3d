/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:13:53 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 15:13:58 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	count_lines(const char *file_name)
{
	size_t	lines;
	char	c;
	int		fd;

	lines = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			++lines;
	close(fd);
	return (lines);
}

void	set_color(t_vec3 *coord, char **text)
{
	int i;

	if (text[1] != NULL)
	{
		coord->color = ft_hextoi(text[1]);
	}
	else
	{
		coord->color = (255) + (((255)) << 16) + (((255)) << 8);
	}
	i = 0;
	while (text[i] != NULL)
	{
		free(text[i]);
		i++;
	}
	free(text);
}

void	get_coords(int fd, t_obj *o, char *line)
{
	t_xcoords	x;
	int			j;
	int			i;

	j = 0;
	while (get_next_line(fd, &line) == 1 && j <= o->rows)
	{
		x = ft_strsplitcount(line, ' ');
		i = 0;
		o->coords[j] = (t_vec3 *)malloc(sizeof(t_vec3) * (x.num_coords + 1));
		while (i < x.num_coords - 1)
		{
			o->coords[j][i].x = i;
			o->coords[j][i].y = j;
			o->coords[j][i].z = ft_atoi(x.coords[i]);
			set_color(&o->coords[j][i], ft_strsplit(x.coords[i], ','));
			free(x.coords[i]);
			i++;
		}
		j++;
		free(x.coords[i]);
		free(x.coords);
	}
	o->col = i;
}

int		load_coords(const char *map, t_obj *o)
{
	int		fd;
	char	*line;

	line = NULL;
	o->rows = count_lines(map);
	o->coords = (t_vec3 **)malloc(sizeof(t_vec3 *) * o->rows);
	fd = open(map, O_RDONLY);
	if (fd != -1)
	{
		get_coords(fd, o, line);
		free(line);
		close(fd);
	}
	else
	{
		ft_putstr("Incorrect file specified\n");
		return (0);
	}
	return (1);
}
