/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:50:15 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/08 14:20:39 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	convert_ascii_to_double(int i, const char *nptr, int negative,
		double result)
{
	double	decimal_divisor;
	int		is_fractional;

	decimal_divisor = 1.0;
	is_fractional = 0;
	while ((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '.'
		|| nptr[i] == ',')
	{
		if (nptr[i] == '.' || nptr[i] == ',')
		{
			is_fractional = 1;
			i++;
		}
		result = result * 10 + (nptr[i] - '0');
		if (is_fractional)
			decimal_divisor *= 10.0;
		i++;
	}
	result = result / decimal_divisor;
	if (negative)
		result *= -1.0;
	return (result);
}

int	fractional_checker(int i, int is_fractional, const char *nptr)
{
	while (nptr[i] != '\0')
	{
		if ((nptr[i] >= '0' && nptr[i] <= '9') || (nptr[i] == '.'
				&& is_fractional != TRUE) || (nptr[i] == ','
				&& is_fractional != TRUE))
		{
			if (nptr[i] == ',' || nptr[i] == '.')
				is_fractional = TRUE;
			i++;
		}
		else
			return (1);
	}
	if (i > 17)
		return (1);
	return (0);
}
// Function to convert the arg into a double type of data
// check if white space, check if negative or positive
// check if there is not a weird input
// then convert

double	ft_atop(const char *nptr, t_set_call *param, t_mlx *screen)
{
	int	i;
	int	negative;
	int	is_fractional;

	is_fractional = FALSE;
	negative = FALSE;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative = TRUE;
		i++;
	}
	if (nptr[i] == '\0')
		free_all(screen, param, 3);
	if (nptr[i] <= '.' && nptr[i] >= ',')
		free_all(screen, param, 3);
	if (fractional_checker(i, FALSE, nptr) == 1)
		free_all(screen, param, 3);
	return (convert_ascii_to_double(i, nptr, negative, 0.0));
}
