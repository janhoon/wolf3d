/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:26:49 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 15:26:52 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_coords(t_obj *o)
{
	int x;
	int	y;

	y = 0;
	while (y < o->rows)
	{
		x = 0;
		while (x <= o->col)
		{
			o->coords[y][x].x *= o->scale.x;
			o->coords[y][x].y *= o->scale.x;
			o->coords[y][x].z *= o->scale.x / 2;
			o->coords[y][x].x += o->pos.x;
			o->coords[y][x].y += o->pos.y;
			o->coords[y][x].z += o->pos.z;
			x++;
		}
		y++;
	}
	o->mid.x = (o->col + 1) * o->scale.x / 2;
	o->mid.y = (o->rows + 1) * o->scale.x / 2;
}

void	init_coords(t_obj *o)
{
	int x;
	int	y;

	if (o->scale.x > o->scale.y)
		o->scale.x = o->scale.y;
	else
		o->scale.y = o->scale.x;
	o->pos.x = (WINDOW_WIDTH - (o->col * (o->scale.x))) / 2;
	o->pos.y = (WINDOW_HEIGHT - (o->rows * (o->scale.y))) / 2;
	o->pos.z = MARGIN;
	set_coords(o);
	y = 0;
	while (y < o->rows)
	{
		x = 0;
		while (x <= o->col)
		{
			rotatez(30.0, &o->coords[y][x], o->mid);
			rotatex(35.0, &o->coords[y][x], o->mid);
			x++;
		}
		y++;
	}
}
