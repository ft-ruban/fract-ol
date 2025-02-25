/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:53:21 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/25 09:21:05 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int main(int argc, char *argv[])
{
	int set_num;
	t_mlx screen; //TOLEARN it was a pointer I had to malloc free blabla learn about it
	t_complex	c;
	if (is_sets_available(argv, &set_num, argc, &c) == 1) //TODO modify for julia
		return (error_msg());

	if (init_screen_mlx(&screen) == NULL)
		return(error_msg());
	sets(set_num, &screen, &c);
	mlx_hook(screen.mlx_win, 17, 1L<<17, cross_window, &screen);
	mlx_hook(screen.mlx_win, 2, 1L<<0, close_window, &screen);
	mlx_loop(screen.mlx); //someone told me it was a good idea here instead in mlx.c

	return(0);	
}

//TODO 
//TODO rm the -g flag in makefile at the end

