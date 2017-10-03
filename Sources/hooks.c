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
			mlx_destroy_window(e->mlx_ptr, e->mlx_window);
			exit(0);
		}
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
