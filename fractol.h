/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:31:30 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/08 18:01:10 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>

#ifndef FRACTOL_H
# define FRACTOL_H

# define C(x, y) ((x) + (y))
#define true = 1
#define false = 0

typedef struct	s_img 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx  
{
	void  *mlx;
	void  *mlx_win;
	t_img	img;
}				t_mlx;
#endif

void	init_screen_mlx(t_mlx *t_mlx);
void 	mandelbrot_set(t_mlx *t_mlx);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);