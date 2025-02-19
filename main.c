/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:53:21 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/19 10:40:14 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//#include <unistd.h>
int main(void)
{
	t_mlx screen; //TOLEARN before it was a pointer I had to malloc free blabla learn about it
	t_complex	c;
	//TODO errors.c (explicit name) 
	init_screen_mlx(&screen); //to init the window it goes to mlx.c
	mandelbrot_set(&screen, &c);//TODO change into ft_sets to determine which sets it will use
	mlx_loop(screen.mlx); //someone told me it was a good idea here instead in mlx.c

    //write(1,"a",1);
    return(0);	
}
