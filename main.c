/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:53:21 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/28 16:28:35 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Main function that will check if the arguments are valid if not it will redirect to an error message then it will init the screen with mlx
//once the screen is set the program continue depending of the fractal type selected and we do also have the two function that allow the feature
//that close the program and created windows properly if you click on the cross OR press ESC
//then it return 0 to signal that the program ended as expected without any errors.
//status : WIP 90%
//TODO create new function to handle the ZOOM feature
//TODOFORBONUS new function to get new colors without changing iter
//TODOFORBONUS new function that change the iter
//TODOFORBONUS zoom feature that follow the MOUSE cursor
//TODOFORBONUS direction arrows 

int main(int argc, char *argv[])
{
	int set_num;
	t_mlx screen; //TOLEARN it was a pointer I had to malloc free blabla learn about it
	t_complex	c;
	int error_code;
	
	if ((error_code = is_sets_available(argv, &set_num, argc, &c)) != 0)
		return (error_msg(error_code));
	if (init_screen_mlx(&screen, argv) == NULL)
	{
		error_code = 6;
		return(error_msg(error_code));
	}
	sets(set_num, &screen, &c);
	mlx_hook(screen.mlx_win, 17, 1L<<17, cross_window, &screen);
	mlx_hook(screen.mlx_win, 2, 1L<<0, close_window, &screen);
	mlx_loop(screen.mlx); //someone told me it was a good idea here instead in mlx.c

	return(0);	
}

//TODO 
//TODO rm the -g flag in makefile at the end

