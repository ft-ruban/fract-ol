/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:47:06 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/19 13:52:37 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h> //to rm with write
void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + (y * data->line_length + x
				* (data->bits_per_pixel))) = color;
}

void	*init_screen_mlx(t_mlx *t_mlx)
{

	t_mlx->mlx = mlx_init();
	if (!t_mlx->mlx)
		return (NULL);
	t_mlx->mlx_win = mlx_new_window(t_mlx->mlx, WIN_HEIGHT, WIN_WIDTH,"proutzor");
	if (!t_mlx->mlx_win)
	{
		mlx_destroy_display(t_mlx->mlx);
		free(t_mlx -> mlx);
		return (NULL);
	}
	t_mlx->img.img = mlx_new_image(t_mlx->mlx, WIN_HEIGHT, WIN_WIDTH);
	if (!t_mlx->img.img)
	{
		mlx_destroy_window(t_mlx->mlx, t_mlx->mlx_win);
		mlx_destroy_display(t_mlx->mlx);
		free(t_mlx -> mlx);
		return (NULL);
	}
	t_mlx->img.addr = mlx_get_data_addr(t_mlx->img.img,
			&(t_mlx->img.bits_per_pixel), &(t_mlx->img.line_length),
			&(t_mlx->img.endian));
	t_mlx->img.bits_per_pixel = t_mlx->img.bits_per_pixel >> 3;
	return(t_mlx);
}
