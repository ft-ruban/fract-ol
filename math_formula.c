#include "fractol.h"

//contain the formula to calculate Mandelbrot fractal.
//status : WIP 90%
//TODO Maybe merge both and move the assignement of z->real_x value elsewhere for mandelbrot. (maybe in error.c?) 

void mandelbrot_formula(t_complex *c, t_complex *z, t_utils *misc_utils)
{
    		z->real_x =  0;
			z->imaginary_y = 0;
			misc_utils->iter = 0;
			while (z->real_x * z->real_x + z->imaginary_y * z->imaginary_y <= 4//useforopti
				&& misc_utils->iter < 256)
			{
				misc_utils->xtemp = z->real_x * z->real_x - z->imaginary_y * z->imaginary_y
					+ c->real_x;
				z->imaginary_y = 2 * z->real_x * z->imaginary_y + c->imaginary_y;
				z->real_x = misc_utils->xtemp;
				misc_utils->iter++;
			}
}

//contain the formula to calculate Julia fractal.
//status : WIP 90%
//TODO Maybe merge both and move the assignement of z->real_x value elsewhere for mandelbrot. (maybe in error.c?)

void julia_formula(t_complex *c, t_complex *z, t_utils *misc_utils)
{
			misc_utils->iter = 0;
			while (z->real_x * z->real_x + z->imaginary_y * z->imaginary_y <= (double)4.0//useforopti
				&& misc_utils->iter < 256)
			{
				misc_utils->xtemp = z->real_x * z->real_x - z->imaginary_y * z->imaginary_y
					+ c->real_x;
				z->imaginary_y = (double)2.0 * z->real_x * z->imaginary_y + c->imaginary_y;
				z->real_x = misc_utils->xtemp;
				misc_utils->iter++;
			}
}





//TORM below before push

/*t_complex	ft_complex_add(t_complex first, t_complex second)
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
}*/
//t_complex 