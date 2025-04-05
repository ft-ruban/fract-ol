/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:50:00 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/05 13:25:30 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//I allocate one octet of memory 
//convert the address into seed to get 
//a pseudo random value
//2^16 = 65536 to get a value between 0 and 65536 (16)bits

int	color_seed(void)
{
	unsigned long	seed;
	void			*ptr;

	ptr = malloc(1);
	if (!ptr)
		return (-1);
	seed = (unsigned long)ptr;
	free(ptr);
	return (seed % (1L << 16));
}

int	get_color(int iter, int color_factor)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	if (iter == 100)
		return (0x000000);
	red = (iter * (color_factor & 0xF)) % 256;
	green = (iter * ((color_factor >> 4) & 0xF)) % 256;
	blue = (iter * ((color_factor >> 8) & 0xF)) % 256;
	return ((red << 16) | (green << 8) | blue);
}
