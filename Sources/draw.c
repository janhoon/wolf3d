/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:42:39 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 15:42:41 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	connect_coord(t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->obj.rows - 1)
	{
		x = 0;
		while (x < e->obj.col - 1)
		{
			draw_line(e, e->obj.coords[y][x], e->obj.coords[y + 1][x]);
			draw_line(e, e->obj.coords[y][x], e->obj.coords[y][x + 1]);
			x++;
			if (x + 1 == e->obj.col)
			{
				draw_line(e, e->obj.coords[y][x], e->obj.coords[y + 1][x]);
			}
		}
		y++;
		if (y == e->obj.rows - 1)
		{
			draw_line(e, e->obj.coords[y][0], e->obj.coords[y][x]);
		}
	}
}

void	draw_object(t_env *e)
{
	e->img.img_ptr = mlx_new_image(e->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	e->img.img_data = (unsigned char *)mlx_get_data_addr(e->img.img_ptr,
		&e->img.img_bpp, &e->img.l_size, &e->img.img_end);
	//connect_coord(e);
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_window, e->img.img_ptr, 0, 0);
}
