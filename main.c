/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:53:21 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/31 16:48:04 by ldevoude         ###   ########lyon.fr   */
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
	t_mlx *screen; //TOLEARN it was a pointer I had to malloc free blabla learn about it
	t_set_call	param;
	int error_code;

	screen = ft_calloc(1, sizeof(t_mlx));
	if (!screen)
		return (0);
	if(init_param(&param, screen) == 1) //DONE
		return (error_msg_malloc(6));
	if ((error_code = is_sets_available(argv, argc, &param)) != 0) //DONE
		return (free_all(screen,&param,error_code));
	if (init_screen_mlx(screen, argv) == NULL) //DONE
		return (free_all(screen,&param,6));	//DONE
	param.screen = screen; //DONE
	mlx_hook(screen->mlx_win, 17, 1L<<17, close_window, &param); //A FAIRE
	mlx_hook(screen->mlx_win, 2, 1L<<0, handle_keys, &param);
	mlx_mouse_hook(screen->mlx_win, zoom, &param);
	mlx_loop_hook(screen->mlx, set, &param);
	mlx_loop(screen->mlx); //someone told me it was a good idea here instead in mlx.c
}


