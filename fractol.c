/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:21:27 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/27 15:45:06 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//need to take care of the security of malloc
int init_param(t_set_call *param) {
    param->c = NULL;//ft_calloc(1, sizeof(t_complex)); //TODO HEREEEEEE
    if(!param->c)
        return (1);
    param->z = ft_calloc(1, sizeof(t_complex));
    if(!param->z)
    {
        //free (param->c);
        return (1);
    }
    param->c->real_x = 0.0;
    param->c->imaginary_y = 0.0;
    param->z->real_x = 0.0;
    param->z->imaginary_y = 0.0;

    param->zoom = 4.0;
    return (change_color(&param->color_factor));
}