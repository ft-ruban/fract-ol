/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:31:30 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/19 16:13:54 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdio.h> //dlt before push
#include <stdlib.h>

#ifndef FRACTOL_H
# define FRACTOL_H

# define true 1
# define false 0
# define WIN_HEIGHT 1920
# define WIN_WIDTH 1080
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

typedef struct s_ratio
{
	int		ratio_y;
	int		ratio_x;
}			t_ratio;
#endif

int 		main(int argc, char *argv[]);
int			get_color(int iter);
void		*init_screen_mlx(t_mlx *t_mlx);
void		mandelbrot_set(t_mlx *mlx, t_complex *c);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int 		is_sets_available(char *argv, int *set_num);
int 		error_msg();
void 		*free_null(void  *target);
void 		sets(int set_num, t_mlx *mlx);
