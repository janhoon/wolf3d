/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:37:50 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 14:37:52 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mlx_run(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->mlx_window);
	draw_object(env);
	mlx_key_hook(env->mlx_window, key_win, env);
	mlx_expose_hook(env->mlx_window, expose_win, env);
	mlx_loop(env->mlx_ptr);
}

int		init_mlx(t_env *env)
{
	env->mlx_ptr = mlx_init();
	if (env->mlx_ptr == NULL)
	{
		ft_putstr("mlx failed to initialize!\n");
		return (0);
	}
	env->mlx_window = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT, "Fils de Fer");
	if (env->mlx_window == NULL)
	{
		ft_putstr("mlx failed to to create a window!\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc == 2)
	{
		if (load_coords(argv[1], &env.obj))
		{
			env.obj.scale.x = (WINDOW_WIDTH - 2 * MARGIN) / (env.obj.col - 1);
			env.obj.scale.y = (WINDOW_HEIGHT - 2 * MARGIN) / (env.obj.rows - 1);
			init_coords(&env.obj);
			if (init_mlx(&env))
			{
				mlx_run(&env);
			}
		}
	}
	else
	{
		ft_putstr("Incorect arguments! Please use \'./fdf path/to/map\'\n");
	}
	return (1);
}
