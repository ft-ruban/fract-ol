#include "fractol.h"

int get_color(int iter)
{
    if (iter == 256)
        return 0x000000; //black for the inside
    return 0xFF0000 + (iter << 8); // shades of red
}
