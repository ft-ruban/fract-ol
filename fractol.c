/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:21:27 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/31 16:46:53 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//need to take care of the security of malloc
int init_param(t_set_call *param, t_mlx *screen)
{
    param->c = ft_calloc(1, sizeof(t_complex));
    if(!param->c)
    {
        free (screen);
        return (1);
    }
    param->z = ft_calloc(1, sizeof(t_complex));
    if(!param->z)
    {
        free (param->c);
        free (screen);
        return (1);
    }
    param->c->real_x = 0.0;
    param->c->imaginary_y = 0.0;
    param->z->real_x = 0.0;
    param->z->imaginary_y = 0.0;
    param->zoom = 4.0;
    if(change_color(&param->color_factor) == 1)
        return (free_all(screen, param, -1));
    else
        return (0);
}

