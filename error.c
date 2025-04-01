/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:42:44 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/01 11:47:33 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h> //TORM BFR PUSH

// to free everything
// status : COMPLETE 100%
int	free_all(t_mlx *screen, t_set_call *param, int error_code)
{
	if (screen)
		free(screen);
	if (param->c)
		free(param->c);
	if (param->z)
		free(param->z);
	if (error_code == 6)
		return (error_msg_malloc(6));
	if (error_code == -1)
		return (1);
	else
		return (error_msg(error_code));
}

int	error_msg_help(void)
{
	ft_printf("To use that program you need to write as first argument");
	ft_printf(" the name of the fractal you are looking for\n\n");
	ft_printf("available sets:\n-Mandelbrot\n-Julia\n\n");
	ft_printf("Mandelbrot doesnt require any parameters but Julia does");
	ft_printf("bellow is a little list of nice looking Julia parameters.\n");
	ft_printf("./fractol Julia 0.12 -0.77\n");
	ft_printf("./fractol Julia 0.83593984038125 0.23254012009216\n");
	ft_printf("./fractol Julia 0.79 0.15\n./fractol Julia -0.7 0.27015\n");
	ft_printf("./fractol Julia -0.162 1.04\n./fractol Julia 0.3 -0.0\n");
	ft_printf("./fractol Julia 0.28 0.008\n./fractol Julia 0.12 -0.77\n");
	ft_printf("./fractol Julia -0.12 -0.77\n./fractol Julia -1.476 0.0\n");
	ft_printf("use ESC or close the window by clicking on the window cross ");
	ft_printf("to close the program\nto zoom in and out use the mouse wheel\n");
	return (0);
}
// Error messages that function will print a predefined
// error message to warn the user
// TODO complete with a case 6
// status : COMPLETE 95%

int	error_msg(int error_code)
{
	if (error_code == 1)
	{
		ft_printfd("Error code :%d\n  ", error_code);
		ft_printfd("does not detect any arguments\n");
	}
	else if (error_code == 2)
	{
		ft_printfd("Error code :%d\n", error_code);
		ft_printfd("Mandelbrot should not receive any parameters.\n");
	}
	else if (error_code == 3)
	{
		ft_printfd("Error code :%d\n", error_code);
		ft_printfd("Julia set require two additionnal argument.\n");
	}
	else if (error_code == 4)
		error_msg_help();
	else if (error_code == 5)
	{
		ft_printfd("Error code : %d\n", error_code);
		ft_printfd("I cannot recognize your arguments, check for any typos");
		ft_printfd("and if your fractal does exist inside of the program.\n");
	}
	ft_printfd("do not hesitate to use the help argument (./fractol Help)");
	return (error_code);
}

int	error_msg_malloc(int error_code)
{
	ft_printfd("Error code : %d \nthere was an issue with memory allocation\n",
		error_code);
	return (error_code);
}

// will determine which fractal was selected set set_num with
// the right numbercode verify if the number of arguments
// are valids and setup what need to be
// set up at the start (like the x-y value of Julia fractal that was given
// by the user at launch) if error return 1 that will then lead to Error msg.
// status : COMPLETE 100%

int	is_sets_available(char **argv, int argc, t_set_call *param)
{
	if (argc == 1)
		return (1);
	else if (!ft_strcmp(argv[1], "Mandelbrot"))
	{
		if (argc != 2)
			return (2);
		param->mandelbrot = TRUE;
		return (0);
	}
	else if (!ft_strcmp(argv[1], "Julia"))
	{
		if (argc != 4)
			return (3);
		param->mandelbrot = FALSE;
		param->c->real_x = ft_atop(argv[2]);
		param->c->imaginary_y = ft_atop(argv[3]);
		return (0);
	}
	else if (!ft_strcmp(argv[1], "Help"))
		return (4);
	else
		return (5);
}
