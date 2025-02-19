#include "fractol.h"

t_complex	ft_complex_add(t_complex first, t_complex second)
{
	t_complex result;
	result.real_x = first.real_x + second.real_x;
	result.imaginary_y = first.imaginary_y + second.imaginary_y;
    return (result);
}
t_complex 	ft_complex_mul(t_complex first, t_complex second)
{
    t_complex result;

    result.real_x = first.real_x * second.real_x - first.imaginary_y * second.imaginary_y;
    result.imaginary_y = first.real_x * second.imaginary_y + first.imaginary_y * second.real_x;
    return (result);
}