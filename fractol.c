/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:21:27 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/07 15:24:43 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_param(t_set_call *param) {
    param->c = ft_calloc(1, sizeof(t_complex));
    param->z = ft_calloc(1, sizeof(t_complex));
    param->c->real_x = 0.0;
    param->c->imaginary_y = 0.0;
    param->z->real_x = 0.0;
    param->z->imaginary_y = 0.0;

    param->zoom = 4.0;
    change_color(&param->color_factor);
}