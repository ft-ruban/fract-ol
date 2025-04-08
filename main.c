/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:53:21 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/05 11:08:00 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// init the screen struct
// launch init_param if malloc fail return related error
// check the entry
// 0 mean it went well
// another value mean that something happened
// said value would be used as an error code
// to return a specific msg and free everything
// init screen for mlx
// we associate the screen ptr in param to screen struct
// commands to close win to handle keyboards
// and mouse actions
// loop to launch set necessary to change it each time 
// user does an action 
// loop to keep the program running

int	main(int argc, char *argv[])
{
	t_mlx		*screen;
	t_set_call	param;
	int			error_code;

	screen = ft_calloc(1, sizeof(t_mlx));
	if (!screen)
		return (0);
	if (init_param(&param, screen) == 1)
		return (error_msg_malloc(6));
	error_code = is_sets_available(argv, argc, &param, screen);
	if (error_code != 0)
		return (free_all(screen, &param, error_code));
	if (init_screen_mlx(screen, argv) == NULL)
		return (free_all(screen, &param, 6));
	param.screen = screen;
	mlx_hook(screen->mlx_win, 17, 1L << 17, close_window, &param);
	mlx_hook(screen->mlx_win, 2, 1L << 0, handle_keys, &param);
	mlx_mouse_hook(screen->mlx_win, zoom, &param);
	mlx_loop_hook(screen->mlx, set, &param);
	mlx_loop(screen->mlx);
}
