/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:47:06 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/20 17:54:53 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h> //to rm with write

int 	close_window(int keycode, t_mlx *t_mlx)
{
	printf("keycode : %d", keycode); //65307 for ESC
	if(keycode == 65307)
	{
		if(t_mlx->mlx_win)
			mlx_loop_end(t_mlx->mlx);
		if(t_mlx->img.img)
			mlx_destroy_image(t_mlx->mlx, t_mlx->img.img);
		if(t_mlx->mlx_win)
			mlx_destroy_window(t_mlx->mlx, t_mlx->mlx_win);
	if(t_mlx->mlx)	
	{
		mlx_destroy_display(t_mlx->mlx);
		free(t_mlx->mlx);
	}
	//mlx_loop_end(t_mlx->mlx);
	exit(0);
	}

	return (0);
}
//TODO file command to store everything <3

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
	t_mlx->mlx_win = mlx_new_window(t_mlx->mlx, WIN_WIDTH, WIN_HEIGHT,"proutzor");
	if (!t_mlx->mlx_win)
	{
		mlx_destroy_display(t_mlx->mlx);
		free(t_mlx -> mlx);
		return (NULL);
	}
	t_mlx->img.img = mlx_new_image(t_mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
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
