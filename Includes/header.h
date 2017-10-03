/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:49:28 by janhoon           #+#    #+#             */
/*   Updated: 2017/09/20 16:49:29 by janhoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define MARGIN 200

# include <stdio.h>
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct		s_draw
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				dy;
	int				dx;
	int				stepx;
	int				stepy;
	int				fraction;
}					t_draw;

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_vec3;

typedef struct		s_obj
{
	t_vec3			**coords;
	t_vec3			pos;
	int				col;
	int				rows;
	t_vec3			scale;
	t_vec3			mid;
}					t_obj;

typedef struct		s_mlx_img
{
	void			*img_ptr;
	unsigned char	*img_data;
	int				img_bpp;
	int				l_size;
	int				img_end;
	int				local_end;
}					t_mlx_img;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*mlx_window;
	t_mlx_img		img;
	t_obj			obj;
}					t_env;

int					key_win(int key, t_env *e);
int					expose_win(t_env *e);
int					load_coords(const char *map, t_obj *o);
int					count_rows(const char *map);

void				draw_object(t_env *e);
void				init_coords(t_obj *o);
void				rotatez(float angle, t_vec3 *points, t_vec3 mid);
void				rotatex(float angle, t_vec3 *points, t_vec3 mid);
void				rotatey(float angle, t_vec3 *points, t_vec3 mid);
void				update_coords(t_obj *o);
void				translate(float x, float y, t_obj *o);
void				rotate(float x, float y, float z, t_obj *o);
void				draw_line(t_env *e, t_vec3 co1, t_vec3 co2);
void				draw_pixel(t_mlx_img *img, int dx, int dy, int *color);

#endif
