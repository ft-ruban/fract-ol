/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formula.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:07:54 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/05 13:25:24 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//reverse z->imaginary_y to avoid reverse
//While the magnitude of z (z^2 + c) is within the boundary
//of 4.0 (this is within the Mandelbrot field)
//or the iteration count has not reached the maximum (150 iterations)
//Julia formula : z = z^2 + c
//calc the new real and imaginary part of z
//xtemp holds the real part of z^2 + c
//then we calculate the new imaginary
//part (2 * real * imaginary part of z)
//update real part of z with the new value
//then increment the iter counter.
void	julia_formula(t_complex *z, t_complex *c, t_utils *misc_utils)
{
	z->imaginary_y = -z->imaginary_y;
	misc_utils->iter = 0;
	while (z->real_x * z->real_x + z->imaginary_y * z->imaginary_y <= 4.0
		&& misc_utils->iter < 100)
	{
		misc_utils->xtemp = z->real_x * z->real_x - z->imaginary_y
			* z->imaginary_y + c->real_x;
		z->imaginary_y = 2.0 * z->real_x * z->imaginary_y + c->imaginary_y;
		z->real_x = misc_utils->xtemp;
		misc_utils->iter++;
	}
}
