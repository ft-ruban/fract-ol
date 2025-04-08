/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:42:44 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/08 14:30:28 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// to free everything before leaving

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
	exit(4);
}
// Error messages that function will print a predefined
// error message to warn the user

int	error_msg(int error_code)
{
	if (error_code == 1)
		error_msg_help();
	else if (error_code == 2)
	{
		ft_printfd("Error code :%d\n", error_code);
		ft_printfd("Mandelbrot should not receive any parameters.\n");
	}
	else if (error_code == 3)
	{
		ft_printfd("Error code :%d\n", error_code);
		ft_printfd("Julia set require two additionnal argument.\n");
		ft_printfd("(ex: 0.285 + 0.01)\n");
	}
	else if (error_code == 4)
		error_msg_help();
	else if (error_code == 5)
	{
		ft_printfd("Error code : %d\n", error_code);
		ft_printfd("Invalid fractal name\n");
		error_msg_help();
	}
	ft_printfd("do not hesitate to use the help argument (./fractol Help)");
	exit(error_code);
}

int	error_msg_malloc(int error_code)
{
	ft_printfd("Error code : %d \nthere was an issue with memory allocation\n",
		error_code);
	return (error_code);
}

// if argc = 1 it mean we got no instructions at launch
// Mandelbrot should not get anything
// Julia require 2 additional arg
// convert from arg to double if Julia
// that would be the x(real) and y(imaginary)
// to determine the c of Julia
// if Help return help msg
// 5 if nothing suit all those conditions.

int	is_sets_available(char **argv, int argc, t_set_call *param, t_mlx *screen)
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
		if ((!ft_strlen(argv[2]) && (!ft_strlen(argv[3]))))
			return (5);
		param->c->real_x = ft_atop(argv[2], param, screen);
		param->c->imaginary_y = ft_atop(argv[3], param, screen);
		return (0);
	}
	else if (!ft_strcmp(argv[1], "Help"))
		return (4);
	else
		return (5);
}
