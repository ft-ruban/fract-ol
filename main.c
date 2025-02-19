/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:53:21 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/19 09:44:02 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_mlx *screen;
	
	//todo errors.c (explicit name) 
	screen = malloc(sizeof (t_mlx));	
	init_screen_mlx(screen); //to init the window it goes to mlx.c
	mlx_loop(screen->mlx); //someone told me it was a good idea here instead in mlx.c

    free(screen);
    return(0);	
}
