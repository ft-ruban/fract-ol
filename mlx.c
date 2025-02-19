/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:47:06 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/19 10:31:07 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h> //to rm with write
void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + (y * data->line_length + x
				* (data->bits_per_pixel))) = color;
}

void	init_screen_mlx(t_mlx *t_mlx)
{

	t_mlx->mlx = mlx_init();
	//if null
	// return
	t_mlx->mlx_win = mlx_new_window(t_mlx->mlx, WIN_HEIGHT, WIN_WIDTH,
			"proutzor");
	//ifnull
	// return freemlx
	// make a window called hello world! of res 1920,
	// 1080 with the pointer mlx
	t_mlx->img.img = mlx_new_image(t_mlx->mlx, WIN_HEIGHT, WIN_WIDTH);
	//if null
	// return free mlx free win
	t_mlx->img.addr = mlx_get_data_addr(t_mlx->img.img,
			&(t_mlx->img.bits_per_pixel), &(t_mlx->img.line_length),
			&(t_mlx->img.endian));
	t_mlx->img.bits_per_pixel = t_mlx->img.bits_per_pixel >> 3;
	write(1,"a",1);
	return;
}
//todo ask a student if I have to secure those functions (cant find any info about it)
//todo ask a student if it is a good idea to make an header per files