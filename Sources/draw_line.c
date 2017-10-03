/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:57:53 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 15:57:55 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_pixel(t_mlx_img *img, int dx, int dy, int *color)
{
	int				i;
	int				y;
	int				x;
	unsigned char	*ptr;

	if ((dx > 0 && dx < WINDOW_WIDTH) && (dy > 0 && dy < WINDOW_HEIGHT))
	{
		x = dx;
		y = dy;
		ptr = (img->img_data) + y * (img->l_size);
		i = 3;
		while (i >= 0)
		{
			*(ptr + x * 4 + i) = ((unsigned char *)(color))[i];
			i--;
		}
	}
}

void	set_steps(t_draw *a)
{
	if (a->dy < 0)
	{
		a->dy = -a->dy;
		a->stepy = -1;
	}
	else
	{
		a->stepy = 1;
	}
	if (a->dx < 0)
	{
		a->dx = -a->dx;
		a->stepx = -1;
	}
	else
	{
		a->stepx = 1;
	}
}

void	draw_x(t_draw *a, t_env *e, t_vec3 co1)
{
	a->fraction = a->dy - (a->dx >> 1);
	while (a->x0 != a->x1)
	{
		if (a->fraction >= 0)
		{
			a->y0 += a->stepy;
			a->fraction -= a->dx;
		}
		a->x0 += a->stepx;
		a->fraction += a->dy;
		draw_pixel(&e->img, a->x0, a->y0, &co1.color);
	}
}

void	draw_y(t_draw *a, t_env *e, t_vec3 co1)
{
	a->fraction = a->dx - (a->dy >> 1);
	while (a->y0 != a->y1)
	{
		if (a->fraction >= 0)
		{
			a->x0 += a->stepx;
			a->fraction -= a->dy;
		}
		a->y0 += a->stepy;
		a->fraction += a->dx;
		draw_pixel(&e->img, a->x0, a->y0, &co1.color);
	}
}

void	draw_line(t_env *e, t_vec3 co1, t_vec3 co2)
{
	t_draw	a;

	a.x0 = co1.x;
	a.x1 = co2.x;
	a.y0 = co1.y;
	a.y1 = co2.y;
	a.dy = a.y1 - a.y0;
	a.dx = a.x1 - a.x0;
	set_steps(&a);
	a.dy <<= 1;
	a.dx <<= 1;
	draw_pixel(&e->img, a.x0, a.y0, &co1.color);
	if (a.dx > a.dy)
		draw_x(&a, e, co1);
	else
		draw_y(&a, e, co1);
}
