/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:45:26 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 14:45:35 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotatez(float angle, t_vec3 *points, t_vec3 mid)
{
	float	temp;

	temp = points->x;
	angle = angle * M_PI / 180.0;
	points->x = mid.x + (points->x - mid.x) * cos(angle) - (points->y - mid.y)
	* sin(angle);
	points->y = mid.y + (temp - mid.x) * sin(angle) + (points->y - mid.y)
	* cos(angle);
}

void	rotatex(float angle, t_vec3 *points, t_vec3 mid)
{
	float	temp;

	temp = points->y;
	angle = angle * M_PI / 180.0;
	points->y = mid.y + (points->y - mid.y) * cos(angle) - points->z
	* sin(angle);
	points->z = (temp - mid.y) * sin(angle) + points->z * cos(angle);
}

void	rotatey(float angle, t_vec3 *points, t_vec3 mid)
{
	float	temp;

	temp = points->z;
	angle = (angle * M_PI) / 180.0;
	points->z = points->z * cos(angle) - points->x * sin(angle);
	points->x = mid.x + temp * sin(angle) + (points->x - mid.x) * cos(angle);
}

void	translate(float x, float y, t_obj *o)
{
	int	i;
	int	j;

	j = 0;
	while (j < o->rows)
	{
		i = 0;
		while (i <= o->col)
		{
			o->coords[j][i].x += x;
			o->coords[j][i].y += y;
			i++;
		}
		j++;
	}
}

void	rotate(float xa, float ya, float za, t_obj *o)
{
	int	x;
	int	y;

	y = 0;
	while (y < o->rows)
	{
		x = 0;
		while (x <= o->col)
		{
			rotatez(za, &o->coords[y][x], o->mid);
			rotatey(ya, &o->coords[y][x], o->mid);
			rotatex(xa, &o->coords[y][x], o->mid);
			x++;
		}
		y++;
	}
}
