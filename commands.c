/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:07:55 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/05 10:38:17 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_set_call *param)
{
	ft_printf("Closing\n");
	if (param->screen->mlx_win)
		mlx_loop_end(param->screen->mlx);
	if (param->screen->img.img)
		mlx_destroy_image(param->screen->mlx, param->screen->img.img);
	if (param->screen->mlx_win)
		mlx_destroy_window(param->screen->mlx, param->screen->mlx_win);
	if (param->screen->mlx)
	{
		mlx_destroy_display(param->screen->mlx);
		free(param->screen->mlx);
	}
	free(param->c);
	free(param->z);
	free(param->screen);
	exit(0);
}

int	key_move(int keycode, t_set_call *param)
{
	if (keycode == 1)
		param->c->real_x -= param->zoom / 4;
	if (keycode == 2)
		param->c->imaginary_y -= param->zoom / 4;
	if (keycode == 3)
		param->c->real_x += param->zoom / 4;
	if (keycode == 4)
		param->c->imaginary_y += param->zoom / 4;
	return (0);
}

int	change_color(int *color_factor)
{
	*color_factor = color_seed();
	if (*color_factor == -1)
		return (1);
	else
		return (0);
}

int	handle_keys(int keycode, t_set_call *param)
{
	if (keycode == 65307)
		return (close_window(param));
	if (keycode == 65361 || keycode == 65362 || keycode == 65363
		|| keycode == 65364)
		return (key_move(keycode & 0x7, param));
	else
	{
		if (change_color(&param->color_factor) == 1)
			return (close_window(param));
	}
	return (1);
}

int	zoom(int type, int x, int y, t_set_call *param)
{
	if (type == 4)
	{
		param->zoom *= 0.9;
	}
	else if (type == 5)
	{
		param->zoom *= 1.1;
	}
	if (param->mandelbrot == TRUE)
	{
		param->c->real_x += ((double)x - (WIN_WIDTH / 2)) / WIN_WIDTH
			* param->zoom;
		param->c->imaginary_y += ((double)y - (WIN_HEIGHT / 2)) / WIN_WIDTH
			* param->zoom;
	}
	else
	{
		param->z->real_x += ((double)x - (WIN_WIDTH / 2)) / WIN_WIDTH
			* param->zoom;
		param->z->imaginary_y += ((double)y - (WIN_HEIGHT / 2)) / WIN_WIDTH
			* param->zoom;
	}
	return (0);
}
