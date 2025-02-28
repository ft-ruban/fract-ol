/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:25:03 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/27 11:42:36 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 1

# include "../libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printf_cases(va_list ptr, int i, const char *str,int *ptr_return_value);
int	ft_printfd(const char *str, ...);
int	ft_printfd_cases(va_list ptr, int i, const char *str,int *ptr_return_value);
#endif
