/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:53:21 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/08 17:51:10 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_mlx *screen;
	screen = malloc(sizeof (t_mlx));
	
	init_screen_mlx(screen); //to init the window
	mlx_loop(screen->mlx);

    free(screen);
    return(0);

	//go to sets to create mandelbrot set
	
	// mlx_loop(mlx);
//	return(0);
}
