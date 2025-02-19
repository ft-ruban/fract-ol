/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:53:21 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/19 14:10:52 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//#include <unistd.h>
int main(int argc, char *argv[])
{
	int set_num;
	t_mlx screen; //TOLEARN before it was a pointer I had to malloc free blabla learn about it
	t_complex	c;
	if (argc < 2 || is_sets_available(argv[1], &set_num) == 1)
		return (error_msg());

	if (init_screen_mlx(&screen) == NULL)
		return(error_msg());
	//TODO learn hooks keyboard usage blabla
	//void sets(set_num, &screen);
	mandelbrot_set(&screen, &c);//TODO change into ft_sets to determine which sets it will use
	mlx_loop(screen.mlx); //someone told me it was a good idea here instead in mlx.c
    return(0);	
}

//TODO 
//TODO rm the -g flag in makefile at the end

