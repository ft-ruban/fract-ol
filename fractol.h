/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:31:30 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/27 11:36:58 by ldevoude         ###   ########lyon.fr   */
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
	// int 	ratio_y;
	// int 	ratio_x;
	double	zoom_ratio;
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
#endif

int 		main(int argc, char *argv[]);
int			close_window(int keycode, t_mlx *t_mlx);
int 		cross_window (t_mlx *t_mlx);
void 		julia_formula(t_complex *c, t_complex *z, t_utils *misc_utils);
void 		mandelbrot_formula(t_complex *c, t_complex *z, t_utils *misc_utils);
int			get_color(int iter);
void		*init_screen_mlx(t_mlx *t_mlx);
void		mandelbrot_set(t_mlx *mlx, t_complex *c, t_utils *misc_utils, t_complex *z);
void		julia_set(t_mlx *mlx, t_complex *c, t_utils *misc_utils, t_complex *z);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int 		is_sets_available(char **argv, int *set_num, int argc, t_complex *c);
int 		error_msg(int error_code);
void 		*free_null(void  *target);
void 		sets(int set_num, t_mlx *mlx, t_complex *c);
