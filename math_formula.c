#include "fractol.h"

void julia_formula(t_complex *z, t_complex *c, t_utils *misc_utils) {
    misc_utils->iter = 0;
    while (z->real_x * z->real_x + z->imaginary_y * z->imaginary_y <= 4.0 && misc_utils->iter < 256) {
        misc_utils->xtemp = z->real_x * z->real_x - z->imaginary_y * z->imaginary_y + c->real_x;
        z->imaginary_y = 2.0 * z->real_x * z->imaginary_y + c->imaginary_y;
        z->real_x = misc_utils->xtemp;
        misc_utils->iter++;
    }
}