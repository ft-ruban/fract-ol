/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:30:37 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/05 11:20:06 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//give the coordinate x-y to the pixel inside of my t_set_call param
//convert the coordinates of pixels into a complex plan 

void	pixel_coordinates(t_complex *center, t_utils *pixel, t_complex *out,
		double zoom)
{
	out->real_x = center->real_x + (pixel->x - (WIN_WIDTH / 2))
		/ (double)WIN_WIDTH * zoom;
	out->imaginary_y = center->imaginary_y + (pixel->y - (WIN_HEIGHT / 2))
		/ (double)WIN_WIDTH * zoom;
}

// determine if we are dealing with Julia or Mandelbrot
// if Mandelbrot real_x and imaginary_y == 0.0

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
//check if we are dealing with mandelbrot or not
//then while loop to draw pixel by pixel on the img
//by init the complex plane then determine the boundary of pix
//put the pixe and color it depending of the boundary of pix
//mandelbrot c is 0 while in Julia its defined by user
//once loop is done we put the img to the mlx window
//that function will repeat each time a new parameter is
//sent with keyboard+mouse action

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
