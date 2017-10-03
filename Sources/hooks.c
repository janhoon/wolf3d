/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:54:18 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 14:54:20 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clear_obj(t_obj *o)
{
	int	i;

	i = 0;
	while (i < o->rows)
	{
		free(o->coords[i]);
		i++;
	}
	free(o->coords);
}

void	translate_hook(int key, t_env *e)
{
	if (key == 0xFF51 || key == 123)
	{
		translate(-10, 0, &e->obj);
	}
	else if (key == 0xFF52 || key == 126)
	{
		translate(0, -10, &e->obj);
	}
	else if (key == 0xFF53 || key == 124)
	{
		translate(10, 0, &e->obj);
	}
	else if (key == 0xFF54 || key == 125)
	{
		translate(0, 10, &e->obj);
	}
}

void	rotate_hook(int key, t_env *e)
{
	if (key == 0 || key == 97)
	{
		rotate(0, -10, 0, &e->obj);
	}
	else if (key == 1 || key == 115)
	{
		rotate(10, 0, 0, &e->obj);
	}
	else if (key == 2 || key == 100)
	{
		rotate(0, 10, 0, &e->obj);
	}
	else if (key == 13 || key == 119)
	{
		rotate(-10, 0, 0, &e->obj);
	}
	else if (key == 12 || key == 113)
	{
		rotate(0, 0, -10, &e->obj);
	}
	else if (key == 14 || key == 101)
	{
		rotate(0, 0, 10, &e->obj);
	}
}

int		key_win(int key, t_env *e)
{
	ft_putstr("Key in window: ");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key >= 0)
	{
		if (key == 0xFF1B || key == 53)
		{
			ft_putstr("Quiting...\n");
			clear_obj(&e->obj);
			mlx_destroy_window(e->mlx_ptr, e->mlx_window);
			exit(0);
		}
		translate_hook(key, e);
		rotate_hook(key, e);
		draw_object(e);
	}
	return (1);
}

int		expose_win(t_env *e)
{
	if (e->mlx_ptr != NULL)
	{
		ft_putstr("Window Exposed\n");
	}
	return (1);
}
