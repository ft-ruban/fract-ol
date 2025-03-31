/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:50:00 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/31 16:46:36 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_seed()
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

	if (iter == 256)
		return (0x000000);
	red = (iter * (color_factor & 0xF)) % 256;
	green = (iter * ((color_factor >> 4) & 0xF)) % 256;
	blue = (iter * ((color_factor >> 8) & 0xF)) % 256;
	return ((red << 16) | (green << 8) | blue);
}
