/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:31:30 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/09 17:33:14 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h> //dlt before push

#ifndef FRACTOL_H
# define FRACTOL_H

# define C(x, y) ((x) + (y))
# define true 1
# define false 0
# define WIN_HEIGH 1920
# define WIN_WITH 1080

typedef struct s_complex
{
	double real_x;
	double imaginary_y;
	int 	ratio_y;
	int 	ratio_x;
}	t_complex;

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
	int 	ratio_y;
	int 	ratio_x;
}			t_ratio;
#endif

void		init_screen_mlx(t_mlx *t_mlx);
void		mandelbrot_set(t_mlx *mlx, t_complex c);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);