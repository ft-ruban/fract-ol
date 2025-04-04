/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:30:37 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/04 09:40:27 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// iterate to each pixel
//+ give the middle point of the screen and redirect
// to the right formula depending of the asked fractal
// status : WIP 85%
// TODO: Maybe merge all my fractal and just make a
// condition that would redirect to any formula
// depending of the user's needs
// TODO: See if there any way to improve the perf of that,
// I do believe there is some.

void	pixel_coordinates(t_complex *center, t_utils *pixel, t_complex *out,
		double zoom)
{
	out->real_x = center->real_x + (pixel->x - (WIN_WIDTH / 2))
		/ (double)WIN_WIDTH * zoom;
	out->imaginary_y = center->imaginary_y + (pixel->y - (WIN_HEIGHT / 2))
		/ (double)WIN_WIDTH * zoom;
}

void	initialize_complex(t_set_call *param, t_complex *z, t_complex *c,
		t_utils *misc_utils)
{
	if (param->mandelbrot == TRUE)
	{
		z->real_x = 0.0;
		z->imaginary_y = 0.0;
		pixel_coordinates(param->c, misc_utils, c, param->zoom);
	}
	else
		pixel_coordinates(param->z, misc_utils, z, param->zoom);
}

int	set(t_set_call *param)
{
	t_utils		misc_utils;
	t_mlx		*mlx;
	t_complex	z;
	t_complex	c;

	mlx = param->screen;
	if (param->mandelbrot == FALSE)
		c = *param->c;
	misc_utils.y = 0;
	while (misc_utils.y < WIN_HEIGHT)
	{
		misc_utils.x = 0;
		while (misc_utils.x < WIN_WIDTH)
		{
			initialize_complex(param, &z, &c, &misc_utils);
			julia_formula(&z, &c, &misc_utils);
			my_mlx_pixel_put(&(mlx->img), misc_utils.x, misc_utils.y,
				get_color(misc_utils.iter, param->color_factor));
			misc_utils.x++;
		}
		misc_utils.y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	return (0);
}
