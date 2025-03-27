/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:31:30 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/28 16:32:31 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx_linux/mlx.h"
#include <stdio.h> //dlt before push
#include <stdlib.h>
#include "libftx/libft.h"

#ifndef FRACTOL_H
# define FRACTOL_H

# define true 1
# define false 0
# define MANDELBROT_ID 1
# define JULIA_ID 2
# define WIN_WIDTH 1920 //500 //1920
# define WIN_HEIGHT  1080//500 //1080
# define X_MIN -2.0
# define X_MAX 1.0
# define Y_MIN -1.5
# define Y_MAX 1.5
# define WIN_HEIGHT_HALF WIN_HEIGHT / 2.0
# define WIN_WIDTH_HALF WIN_WIDTH / 2.0
typedef struct s_complex
{
	double	real_x;
	double	imaginary_y;
}			t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}			t_mlx;

typedef struct s_utils
{
	double 	x;
	double 	y; //int if broke
	int 	iter;
	double	xtemp;
}			t_utils;

typedef struct s_set_call
{
	t_mlx		*screen;
	t_complex	*c;
	t_complex	*z;
	double 		zoom;
	int			mandelbrot;
	int 		color_factor;
}			t_set_call;
#endif

int 		main(int argc, char *argv[]);
void 		init_param(t_set_call *param);
int			close_window(t_set_call *param);
int 		change_color(int *color_factor);
int 		key_move(int keycode, t_set_call *param);
int 		handle_keys(int keycode, t_set_call *param);
int 		zoom (int type, int x, int y, t_set_call *param);
void 		julia_formula(t_complex *z, t_complex *c, t_utils *misc_utils);
int 		color_seed();
int			get_color(int iter, int color_factor);
void		*init_screen_mlx(t_mlx *t_mlx, char **argv);
void		mandelbrot_set(t_mlx *mlx, t_complex *c, t_utils *misc_utils, t_complex *z);
void		julia_set(t_mlx *mlx, t_complex *c, t_utils *misc_utils, t_complex *z);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int 		is_sets_available(char **argv, int argc, t_set_call *param);
int 		error_msg(int error_code);
void 		*free_null(void  *target);
void 		pixel_coordinates(t_complex *center, t_utils *pixel, t_complex *out, double zoom);
void 		initialize_complex(t_set_call *param, t_complex *z, t_complex *c, t_utils *misc_utils);
int 		set(t_set_call *param);
