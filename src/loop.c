/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <janhoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 11:21:41 by janhoon           #+#    #+#             */
/*   Updated: 2017/10/10 11:21:42 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		loop_hook(t_env *e)
{
	e->mlx.last_frame = clock();
	if (e->mlx.next_frame > e->mlx.last_frame)
		return (0);
	e->mlx.next_frame = e->mlx.last_frame + (CLOCKS_PER_SEC / 100);
	if (e->player.move_up)
		move_up(e);
	if (e->player.move_down)
		move_down(e);
	if (e->player.move_right)
		move_right(e);
	if (e->player.move_left)
		move_left(e);
	if (e->player.move_jump == 1)
		move_jump(e);
	raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	return (0);
}
