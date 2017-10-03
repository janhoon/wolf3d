/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <janhoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 10:59:53 by janhoon           #+#    #+#             */
/*   Updated: 2017/10/03 11:02:57 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_wolf(t_env *e)
{
	e->wolf.pos.x = 22
	e->wolf.pos.y = 12;
	e->wolf.dir.x = -1
	e->wolf.dir.y = 0;
	e->wolf.plane.x = 0
	e->wolf.plane.y = 0.66;

	e->wolf.time = 0;
	e->wold.oldTime = 0;
}
